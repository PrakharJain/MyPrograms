#include <iostream>
using namespace std;

class NumberPermutation 
{
	public:
		void permutation(int n) 
		{
			int* data = new int[n];

			for (int i = 0; i < n; i++) 
			{
				data[i] = (i+1);
			}

			permutation(data, 0, n);
		}

		void permutation(int* data, int pos , int length) 
		{
			if (pos == length - 1) 
			{
				printArray(data , length);
				return;
			}

			for (int i = pos; i < length; i++) 
			{
				swap(data, i, pos);
				permutation(data, pos+1, length);
				swap(data, i, pos);
			}
		}


		void swap(int* data, int i, int j) 
		{
			int tmp = data[i];

			data[i] = data[j];
			data[j] = tmp;
		}

		void printArray(int* data , int length) {
			for (int i = 0; i < length; i++) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
};
int main() 
{
	NumberPermutation *np = new NumberPermutation();

	np->permutation(4);
}

