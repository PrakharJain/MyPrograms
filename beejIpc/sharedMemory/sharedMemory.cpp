#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 4 /* define a 4 byte long shm segment for sharing a single integer variable */
int * count = NULL;

int main()
{
	key_t key;
	int shmid;
	if( (key = ftok("sharedMemory.cpp" , 'S')) == -1)
	{
		perror(" ftok error");
		exit(1);
	}
	if( (shmid = shmget(key,SHM_SIZE,0644|IPC_CREAT) == -1))
	{
		perror("shmget error");
		exit(1);
	}
	count = (int *)shmat(shmid, (void*)0 , 0);
	if( count == (int *) (-1))
	{
		perror("shmat error");
		exit(1);
	}
}


