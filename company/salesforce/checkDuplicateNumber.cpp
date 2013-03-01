#include<cmath>
#include <stdexcept>
#include <cstring>
using namespace std;
class NumberUtility
{
	public:
		bool checkIfExists(int n);
		NumberUtility();
		~NumberUtility();
	private:
		int * array;
};

NumberUtility::NumberUtility()
{
	int num = pow(2 , sizeof(int) * 8) / (sizeof(int) * 8) ; // represents number of integers
//	needed for representing each integer
		array = new int[num];
	memset(array , 0 , num * sizeof(int));
}

NumberUtility::~NumberUtility()
{
	delete[ ] array;
}

bool NumberUtility::checkIfExists(int n)
{
	if (n < 0)
	{
		throw out_of_range("Only non negative  numbers are  valid" );
	}
	int size = sizeof(int)*8 ;
	int arrayIndex =  n/size;
	int bitTocheck = n%size;
	int num = array[arrayIndex];
	if( (num<< bitTocheck) &&  0xA000)
	{
		return true;
	}
	else
	{
		array[arrayIndex] = array[arrayIndex]  | (1 << bitTocheck);
	}
	return false;
}
