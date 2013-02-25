#include <iostream>
#include <cstdlib>
#include "CircularQueue.h"

using namespace std;

struct ArrayInfo
{

	int * arr;
	int size;
	CircularQueue * queue;
};

void* InsertToQueue(void * arrayInfo);
void CreateThreads(CircularQueue &q);
void ManualInput(CircularQueue &q);

int main()
{
	cout << "Please enter the size of the array " <<endl;
	unsigned int size = 0;
	cin >> size;
	CircularQueue * q = NULL;
	try
	{
		q = new CircularQueue(size);
	}
	catch (std::bad_alloc &except)
	{
		cout << " Exiting. Not enough memory available to allocate queue " <<endl;
		exit(1);
	}

	int choice;
	cout <<  " Please put in the choice \n1.Automated \n2.Manual " << endl;
	cin >> choice;

	switch(choice)
	{
		case 1:
			CreateThreads(*q);
			try
			{
				for (int i = 0 ; i < 4000 ; i++)
				{
					cout << q->Dequeue() << endl;
				}
			}
			catch (std::exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 2:
			ManualInput(*q);
			break;
		default:
			exit(1);
	}

	delete q;
	cout << "Exiting Main " << endl;
}


void CreateThreads(CircularQueue& q)
{
//	int  arr1[] = {1,2,3,4,5,6,7,8,9 ,100 , 101 , 102 , 103 , 104 , 105 , 106 , 107 , 108 , 109 , 110 , 111 , 112 , 113 , 114};
//	int  arr2[] = {10,11,12,13,14,15};
	int arr1[2000];
	int arr2[2000];
	for(int j = 0 ; j < 2000; j++ )
	{
	arr1[1] = j;
	arr2[2] = 20000 + j;
	}
	ArrayInfo info[2];
	info[0].arr = arr1;
	info[1].arr = arr2;
	info[0].size = 2000;
	info[1].size = 2000;
	info[0].queue = &q;
	info[1].queue = &q;


	pthread_t threads[2];
	for(int i = 0 ; i < 2 ; i++)
	{
		//create threads
		int rc = pthread_create(&threads[i],NULL,InsertToQueue, (void*)&info[i]);  
		if(rc)
		{
			cout << ("Error in creating thread %d \n " , rc);
			exit(rc);
		}


	}
	for(int i = 0; i<2; i++)
	{
		void * status;
		cout << "Waiting for thread " <<  i << endl;
		pthread_join(threads[i],&status);
		cout << "Thread  " << i << " exited " << endl;

	}
}


void* InsertToQueue(void * arrayInfo)
{
	ArrayInfo *info = (ArrayInfo*)(arrayInfo);
	cout << " array aize = " << info->size << endl;
	try
	{
		for(int i =0 ; i < info->size ; i++)
		{
			info->queue->Enqueue(i);
			//info->queue->Enqueue(info->arr[i]);
		}
	}
	catch(std::exception &ex)
	{
		cout << ex.what() << endl;
	}
	pthread_exit(0);
}

void ManualInput(CircularQueue &q)
{
	while(1)
	{
		cout << "Please enter your choice \n1. Enqueue \n2.Dequeue \n3.Exit  " << endl;
		int choice;

		cin >> choice;
		switch (choice)
		{
			case 1:
				{
					int data;
					cout << "Put in the data " << endl;
					cin >> data;
					try
					{
						q.Enqueue(data);
					}
					catch(std::exception &ex)
					{
						cout << ex.what() << endl;
					}
					break;
				}
			case 2:
				{
					int element = 0;
					try
					{
						element = q.Dequeue();
					}
					catch(std::exception& ex)
					{
						cout << ex.what() << endl;
						continue;
					}
					cout << "The dequeued element is  " << element << endl;
					break;
				}
			case 3:	
				exit(0);
			default:
				continue;

		}
	}
}
