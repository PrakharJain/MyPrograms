/*
 * Given a value N, if we want to make change for N cents, and we have infinite supply of each of 
 * S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? 
 * The order of coins doesn’t matter.
 * http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */

#include <iostream>
using namespace std;

int coinchange(int * arr , int sum , int index)
{
	if(sum == 0)
	{
		return 1;
	}

	if(sum < 0 || index < 0 )
	{
		return 0;
	}

	//do not include coin  + include the coin
	return coinchange(arr , sum , index-1) + coinchange(arr , sum - arr[index] , index);
}



int main()
{
	int count = 0;
	cout << "Please put in the number of denominations " << endl; 
	cin >> count;
	if(count <= 0 )
		return 0;
	int * denom = new int[count];
	cout << "Please put in the denminations " << endl;
	for(int i =  0 ;  i < count ; i++)
	{
		cin >> denom[i];
	}
	char ch = 'y';
	int sum = 0;
	do
	{
		cout << "Put in the sum ";
		cin >> sum ;
		cout << "No of ways are " <<	coinchange(denom, sum , count-1) << endl;
		cout << "Do you want to continue ? " ;
		cin >> ch;
	}while (ch == 'y' || ch == 'Y');

	delete[] denom;
	return 0;
}
