#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024
#include <iostream>
/* make it a 1K shared memory segment */

int * count = NULL;
int shmid;
int main()
{
        printf("Inside GetAndInitialiseSharedMemory\n");
        key_t key_shm;
        if( (key_shm = ftok("ftokfile" , 'S')) == -1)
        {
                perror(" ftok error");
                exit(1);
        }
//	if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1)
        if ((shmid = shmget(key_shm,SHM_SIZE,0644|IPC_CREAT)) == -1)
        {
                perror("shmget error");
                exit(1);
        }
	std:: cout << " After shmget " << std::endl;
	std::cout <<"SHMID = " <<shmid <<std::endl;
//	data = (char *)shmat(shmid, (void *)0, 0);
        count = (int *)shmat(shmid, (void *)0, 0);
	std::cout << " AFter shmat \n" ;
//        std::cout << " data = "<< data << std::endl;
//      printf("count = %d\n" , (int)count);
        if( count == (int *) (-1))
        {
                perror("shmat error");
                exit(1);
        }
        *count = 0;
//      return shmid;
}

