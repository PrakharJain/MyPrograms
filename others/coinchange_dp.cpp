#include <iostream>
#include <cstring>
using namespace std;

int coinchange(int * denom , int sum , int index, int * sol)
	{
	if(index < 0 )
		return 0;
	if(sum < 0 )
		return 0;

	if(sol[sum] != -1)
		{
		cout << "Returning from array for sum " << sum << "value " << sol[sum] << endl;
		return sol[sum];
		}

//	sol[0] = 1; // there is 1 way to make 0
	cout << "calculating for " << sum << endl;
	sol[sum] = coinchange(denom , sum , index-1, sol)	+ coinchange(denom , sum - denom[index] , index , sol);
	return sol[sum];
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
		int * sol =  new int[sum+1];
		memset(sol , -1 , sizeof(int) * (sum +1));
		sol[0] =1;
                cout << "No of ways are " <<    coinchange(denom, sum , count-1, sol) << endl;
		delete [] sol;
                cout << "Do you want to continue ? " ;
                cin >> ch;
        }while (ch == 'y' || ch == 'Y');

        delete[] denom;
        return 0;
}

