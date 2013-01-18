#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <iostream>
#define MAX_RETRIES 10
#define SHM_SIZE 40 /* define a 4 byte long shm segment for sharing a single integer variable */

int * count = NULL;
int shmid;


void GetAndInitialiseSharedMemory()
{
	printf("Inside GetAndInitialiseSharedMemory\n");
        key_t key_shm;
        if( (key_shm = ftok("ftokfile" , 'S')) == -1)
        {
                perror(" ftok error");
                exit(1);
        }
	if ((shmid = shmget(key_shm,SHM_SIZE,0644|IPC_CREAT)) == -1)
        {
                perror("shmget error");
                exit(1);
        }
        count =  (int*)shmat(shmid, (void*)0 , 0);
//	printf("count = %d\n" , (int)count);
        if( count == (int *) (-1))
        {
                perror("shmat error");
                exit(1);
        }
	*count = 0;
//	return shmid;
}


void GetSharedMemory()
{
        printf("Inside GetSharedMemory\n");
        key_t key_shm;
        if( (key_shm = ftok("ftokfile" , 'S')) == -1)
        {
                perror(" ftok error");
                exit(1);
        }
        if ((shmid = shmget(key_shm,SHM_SIZE,0644|IPC_CREAT)) == -1)
        {
                perror("shmget error");
                exit(1);
        }
        count =  (int*)shmat(shmid, (void*)0 , 0);
//      printf("count = %d\n" , (int)count);
        if( count == (int *) (-1))
        {
                perror("shmat error");
                exit(1);
        }
//      return shmid;
}
union semun
{
	int val;
	struct semid_ds * buf;
	ushort * array;
};

int initsem(key_t key , int nsems)
{
	int i;
	semun arg;
	semid_ds buf;
	sembuf sb;
	int semid;
	semid = semget(key,nsems ,  IPC_CREAT | IPC_EXCL | 0666);
	printf( "After semget\n");
	if(semid >=0)
	{
		printf("semid > 0\n");
		GetAndInitialiseSharedMemory();
		printf("After initialising shared memory \n");
		// prepare  sembuf as it will be passed to semop to initialise the semapores in the semaphore set. 
		sb.sem_op = 1;
		sb.sem_flg = 0;
		// arg.val initialaises the semaphore with the number of resouces available
		arg.val = 1;

		for(sb.sem_num = 0 ; sb.sem_num <nsems ; sb.sem_num ++)
		{
			if(semop(semid , &sb , 1) == -1)
			{
				// error in semop ree the semaphore
				int e = errno;
				semctl(semid , 0 , IPC_RMID); // remove the semphore
				errno = e;
				return -1;
			}
		}
	}
	else if( errno == EEXIST)
	{
		GetSharedMemory();
		// the other process got the seaphore
		int ready = 0;
		semid = semget(key , nsems , 0);
		if(semid < 0)
		{
			// error 
			return semid;
		}
		// wait for other process to initialise semaphore
		arg.buf = &buf;
		for(int i = 0 ; i< MAX_RETRIES ;i++)
		{
			semctl(semid , nsems-1 , IPC_STAT , arg);
			if( arg.buf -> sem_otime != 0 )
			{
				ready = 1;
			}
			else
			{
				sleep(1);
			}
		}
		if(!ready)
		{
			errno = ETIME;
			return -1;
		}

	}
	else
	{
		return semid; // error condition
	}
	return semid;
}





int main(void)
{
	key_t key;
	int semid;
	sembuf sb;
	sb.sem_num = 0;
	sb.sem_op = -1;
//	sb.sem_flg = SEM_UNDO;
	if((key = ftok("ftokfile" , 'A' )) == -1)
	{
		perror("ftok");
		exit(1);
	}
	printf("Key = %d\n" ,key); 
	if((semid = initsem(key , 1)) == -1)
	{
		perror("initsem");
		exit(1);
	}
	printf("After Initsem \n");

	while(1)
	{
		sb.sem_op = -1;
		if(semop(semid,&sb,1) == -1)
		{
			perror("semop lock");
			exit(1);
		}
//		printf("Got lock Process 1 *count ==  %d \n" , *count);
		std::cout << "reached HEre " << std::endl;
		if(  (*count) % 2 == 0 && (*count)  <= 20 )
		{
			printf(" Process 1 %d " , (*count));
			std::cout << "Printed" << std::endl;
			(*count)++;
		}

		if( (*count) > 20)
		{
			// unlock semaphore and exit 
			sb.sem_op = 1; // free the resource
			if(semop(semid , &sb , 1) == -1)
			{
				perror("semop");
			}
			exit(1);
		}

		sb.sem_op = 1; // free the resource
		if(semop(semid , &sb , 1) == -1)
		{
			printf("Entered here \n"); 
			perror("semop");
			exit(1);
		}
	}
}
