#include <iostream>
using namespace std;


void InsertionSort(int * arr , int noOfElements);

int main()
{
	cout << " Put in the number of elements " << endl;
	int noOfElements = 0;
	cin >>  noOfElements;
	cout << "Pease put in the elements to sort "<< endl;
	int * arr = new int[noOfElements];
	for (int i = 0 ; i < noOfElements ; i++)
	{
		cin >> arr[i];
	}
	InsertionSort(arr,noOfElements);
	cout << "The sorted array is " << endl;
	for(int i = 0 ; i<noOfElements; i++)
	{
		cout << arr[i] << endl;
	}
}
void InsertionSort(int * arr , int noOfElements)
{
	// i starts from 1 as the first elemen is already sorted.
	for(int i  = 1 ; i < noOfElements ; i++)
	{
		int temp = arr[i];
		int j = i-1;
		while(temp < arr[j] )
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
	}
}

