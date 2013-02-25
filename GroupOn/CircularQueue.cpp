#include <iostream>
#include <stdexcept>
#include "CircularQueue.h"
#include "Locker.h"
using namespace std;

CircularQueue::CircularQueue(unsigned int sz) :size(sz) , count(0) , front (0) , end(0)
{
	if (size <= 0)
	{
		cout << "Invalid size. Allocating default size ";
		size = DEFAULT_ARRAY_SIZE; 
	}

	try
	{
		array = new int[size];
	}
	catch (std::bad_alloc & ex)
	{
		cout << " Failed to Initialize array for queue " << endl;
		throw;
	}
	pthread_mutex_init(&mutex , NULL);
}

CircularQueue::~CircularQueue()
{
	delete[] array;
	pthread_mutex_destroy(&mutex);
}

void CircularQueue::Enqueue(int data)
{
	Locker lock(mutex);
	if(count < size)
	{
		array[ end ] = data;
		end = (end + 1 ) % size;
		count++;
	}
	else
	{
		throw std::overflow_error("Not enough space on the queue");
	}
}

int CircularQueue::Dequeue()
{
	Locker lock(mutex);
		if(count == 0 )
		{
			throw std::underflow_error("Queue empty");
		}
	int data =  array[front];
	count--;
	front = (front +1)% size;
	return data;
}

void CircularQueue::Initialize(int * arr , int size)
{
	if(size > this->size)
		return;
	for (int i = 0 ; i <size ; i++)
	{
		Enqueue(arr[i]);
	}
}	
