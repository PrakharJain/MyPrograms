
// refer https://computing.llnl.gov/tutorials/pthreads/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * print_message(void * msg)
{
	char *s = (char*)(msg);
	printf("%s \n" , s);
	pthread_exit(0);
}


int main()
{
	pthread_t threads[2];
	char str[2][40] = {"Thread one " , "Thread Two " };
	for(int i = 0 ; i < 2 ; i++)
	{
		//create threads
		int rc = pthread_create(&threads[i],NULL,print_message, (void*)&str[i]);  // here NULL is pthread_attr_t
		if(rc)
		{
			printf("Error in creating thread %d \n " , rc);
			exit(rc);
		}


	}
	for(int i = 0; i<2; i++)
	{
		void * status;
		printf("Waiting for thread %d\n" , i);
		pthread_join(threads[i],&status);
		printf("Thread exited \n");

	}
	printf("Exiting main.\n");
	pthread_exit(NULL );
} 
