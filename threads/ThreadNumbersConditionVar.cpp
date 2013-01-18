#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int count = 0;
pthread_mutex_t mutex;
pthread_cond_t condVar;

void * CounterThread1 (void * arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if (count % 2 == 0 && count <= 20)
		{
			printf("Thread1 : %d \n" , count);
			count++;
		}
		else
		{
			pthread_cond_signal(&condVar);
		}
		if(count > 20)
		{
			pthread_cond_signal(&condVar);
			pthread_mutex_unlock(&mutex);		
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&mutex);		
	}		
}


void * CounterThread2(void * arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&condVar, &mutex);
		if(count % 2 == 1 && count <= 20)
		{
			printf("Thread2 : %d \n" , count);
			count++;
		}
		else
		{
			pthread_cond_signal(&condVar);
		}


		if(count > 20)
		{
			pthread_mutex_unlock(&mutex);		
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&mutex);		
	}
}

int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&condVar , NULL);

	pthread_t threads[2];
	pthread_create(&threads[0] , NULL , CounterThread1 , NULL);
	pthread_create(&threads[1] , NULL , CounterThread2 , NULL);

	for (int i = 0 ; i < 2 ; i++)
	{
		void * status;
		pthread_join(threads[i], &status);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&condVar);
	pthread_exit(NULL);
}
