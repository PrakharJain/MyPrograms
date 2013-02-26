#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <memory>
#include <pthread.h>

const int DEFAULT_ARRAY_SIZE = 100;

class CircularQueue
{
	public:
		/* 
		 * constructor
		 * @param the size of the queue that will be created
		 */
		CircularQueue(unsigned int sz);

		~CircularQueue();

		/*
		 * @param data - The data that will be enqueued in the queue
		 * @ return void
		 * throws exception on overflow.
		 */
		void Enqueue(int data);

		/*
		 * @return - The data dequeued fro the front of the queue
		 * throws exception on underflow
		 */

		int Dequeue();
		/*
		 * @param arr - the pointer to the array containing the elements with which the queue needs to be initialised.
		 * @param size - The number of elements in arr 
		 * @return void
		 */
		void Initialize(int * arr , int size);	
	private:
		/*
		 * array to hold he elements of the queue;
		 */
		int * array;
	
		/*
		 * Location of the front element of the queue
		 */
		unsigned int front;
	
		/*
		 * Location of the last element in the queue
		 */
		unsigned int end; 

		/*
		 * The number of elements in the queue
		 */
		unsigned int count;
		
		/*
		 * The total capacity of the queue i.e the number of elements that can be stored in the queue.
		 */
		unsigned int size;
		/*
		 * mutex to ensure the Enqueue and Dequeue is thread safe.
		 */
		pthread_mutex_t mutex;
};



#endif // CIRCULAR_QUEUE_H
