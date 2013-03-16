#include <iostream>
using namespace std;

void swap(int & a , int & b)

{
	int temp = a;
	a = b;
	b = temp;
}

int Partition( int * arr , int low , int high)
{
	int i = low -1;
	int pivot = arr[high];
	for(int j = low ; j<high ; j++)
	{
		if(arr[j] <= pivot)
		{
			i = i+1;
			swap(arr[j] ,arr[i]);
		}
	}
	i = i+1;
	swap(arr[high] , arr[i]);
	return i;
}  

void QuickSort(int *arr , int low , int high)
{
	if(low < high)
	{
		int i = Partition(arr , low , high);
		QuickSort(arr ,low , i-1);
		QuickSort(arr,i+1 , high);
	}
}


int main()
{
	int arr[100];
	cout << "Please Enter the numbers -9999 to stop." << endl;
	int num;
	cin >> num;
	int i = -1;
	while(num != -9999)
	{
		i++;
		arr[i] = num;
		cin >> num;
	}
	QuickSort(arr,0, i);
	for(int j = 0 ; j <=i ; j++)
	{
		cout << arr[j];
	}
}
