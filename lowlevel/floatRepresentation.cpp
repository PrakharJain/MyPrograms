#include <iostream>
#include <string>
using namespace std;

int main( int argc, char* argv[] ) {
	float num; // = atof( argv[1] );
	int *ip = (int*)&num;
	int size, digit;
	string ch;
	string binstr;
	size = sizeof(num);
	cout << "sizeof int = " << sizeof(size) << endl;
	cout << "sizeof float = " << sizeof(num) << endl;

	for( int k = 0; k < 10; ++k ) 
	{
		num = k;
		for( int j = 0; j < size; ++j ) 
		{
			for( int i = 0; i < 8; ++i ) 
			{
				digit = 1 & (*ip);
				ch = string( 1, (char)(48 + digit) );
				binstr.insert( 0, ch );
				*ip >>= 1;
			}
			binstr.insert( 0, " ");
		}
		cout << k << "   " <<  binstr << endl;
		binstr = "";
	}

	return 0;
}
