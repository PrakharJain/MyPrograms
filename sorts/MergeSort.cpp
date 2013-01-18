#include <iostream>
using namespace std;


void merge(int * arr , int start , int mid , int end);
void mergesort(int * arr , int start , int end)
{
	if(start >= end)
		return; 
	int mid = (start + end) / 2;
	mergesort(arr , start , mid);
	mergesort(arr , mid+1 , end);
	merge(arr , start , mid , end);
}


// here start is the index of start of first division and mid is the index of end of first division
// also mid +1 is the index of start of first division and end is the index of end of first division
void merge(int * arr , int start , int mid , int end)
{
	int length1 = mid - start + 1;
	int length2 = end - mid;

	int * a1 =  new int[length1];
	int * a2 = new int[length2];
	// copy all the elements till mid from arr to a1 
	for(int i =0 , j = start ; j<=mid ; j++,i++)
	{
		a1[i] = arr[j];
	}

	// copy all the elements from mid + 1 to end from arr 2 to a2;
	for(int i = 0 , j = mid+1; j<=end ; j++,i++)
	{
		a2[i]=arr[j];
	};

	int i =0 , j =0 , k =start;
	while( i <  length1  && j < length2)
	{
		if(a1[i] < a2[j])
		{
			arr[k] = a1[i];
			k++;
			i++;
		}	 	
		else
		{
			arr[k] = a2[j];
			k++;
			j++;
		}
	}
	while(i<length1)
	{
		arr[k] = a1[i];
		i++;
		k++;
	}

	while ( j < length2)
	{
		arr[k] = a2[j];
		j++;
		k++;
	}

	delete [] a1;
	delete [] a2;
}

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
	mergesort(arr,0,noOfElements-1);
	cout << "The sorted array is " << endl;
	for(int i = 0 ; i<noOfElements; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
}

