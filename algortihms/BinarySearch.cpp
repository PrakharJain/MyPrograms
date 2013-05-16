#include <iostream>
using namespace std;

int BinarySearch(int a[] , int l , int r , int key)
{


	while(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] == key)
		{
			return mid;
		}
		if(key < a[mid])
		{
			r = mid -1;
		}
		else
		{
			l = mid +1;
		}
	}
	return -1;
}


int main()
{
	int arr[100];
	cout << "Please put in the elements of the array. -9999 to stop." << endl;
		int val;
	cin >>  val;
	int i = 0;
	while(val != -9999)
	{
		arr[i] = val;
		i++;
		cin >> val;
	}
	int key;
	cout << "Put in the element to search " << endl;
	cin >> key;
	int pos;
	if( (pos = BinarySearch(arr,0,i,key)) == -1 )
	{
		cout << "Not found " << endl;
	}
	else
	{
		cout << "Found at position " << pos << endl;
	}
}
