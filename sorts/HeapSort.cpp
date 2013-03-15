#include <iostream>
using namespace std;


template <class T ,  int cap>
class Heap
{
	public:
		void MaxHeapifyTopDown(int i);
		int parent(int i);
		int leftChild( int i);
		int rightChild (int i);
		void MaxHeapifyBottomUp(int i);
		int root();
		void Insert(T data);
		void swap(T &a , T&b);
		void Heapsort();
		void PrintHeap();
		T arr[cap];
		int size;
		int capacity;
		Heap()
		{
			capacity = cap;
			size =0;
		}
};

template <class T , int cap> void Heap<T,cap>::PrintHeap()
{
	for (int i = 1 ; i <=size ; i++)
	{
		cout << " " << arr[i] ;
	}
}
template <class T , int cap> void Heap<T,cap>::swap(T&a , T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

	template<class T , int cap>
int Heap<T,cap>::parent(int i)
{
	return i/2; 
}

	template<class T , int cap>
int Heap<T,cap>::leftChild(int i)
{
	return 2*i;
}


	template<class T , int cap>
int Heap<T,cap>::rightChild(int i)
{
	return 2*i+1;
}

	template<class T , int cap>
void Heap<T,cap>::MaxHeapifyTopDown(int i) // ensure Heap property index i onwards.
{
	int left = leftChild(i);
	int right = rightChild(i);
	int largest = i;
	if(left <=  size && arr[left] > arr[largest])
		largest = left;

	if(right <= size && arr[right] > arr[largest])
		largest = right;

	if(largest != i)
	{
		T temp;
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		MaxHeapifyTopDown(largest);
	}
}

	template<class T , int cap>
int Heap<T,cap>::root()
{
	return 1;
}

template<class T , int cap>
void Heap<T,cap>::MaxHeapifyBottomUp(int i)
{
	if(i == root())
		return;
	int parentIndex = parent(i);
	int largest = parentIndex;
	if(arr[i] > arr[parentIndex])
	{
		largest = i;
	}

	if(largest != parentIndex)
	{
		T temp = arr[i];
		arr[i] = arr[parentIndex];
		arr[parentIndex] = temp;
		MaxHeapifyBottomUp(parentIndex);
	}

}

	template <class T , int cap>
void Heap<T,cap>::Insert(T data)
{
	size = size +1 ;
	arr[size] = data;
	MaxHeapifyBottomUp(size);
}

	template<class T , int cap>
void Heap<T,cap>::Heapsort()
{

	for(int i = size ; i>=2 ; i--)
	{
		swap(arr[1] , arr[i]);
		cout << arr[i] << " " ;
		size = size -1;
		MaxHeapifyTopDown(1);
	}
	cout << arr[1] << endl;
}
int main()
{
	Heap<int , 100> h;
	h.Insert(4);
	h.Insert(8);
	h.Insert(2);
	h.Insert(5);
	cout << "Sorted Heap is " << endl;
	h.Heapsort();
};
