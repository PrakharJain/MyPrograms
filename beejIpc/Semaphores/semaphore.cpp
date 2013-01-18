#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define MAX_RETRIES 10

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

	if(semid >=0)
	{
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
	sb.sem_flg = SEM_UNDO;
	if((key = ftok("semaphore.cpp" , 'A' )) == -1)
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

	printf("Press return to lock :");
	getchar();
	printf("Trying to Lock .... \n");
	if(semop(semid,&sb,1) == -1)
	{
		perror("semop");
		exit(1);
	}

	printf ("Locked \n");
	printf("Press Return to unlock \n");
	getchar();

	sb.sem_op = 1; // free the resource
	if(semop(semid , &sb , 1) == -1)
	{
		perror("semop");
		exit(1);
	}
	printf("unlocked");
	return 0;
}
