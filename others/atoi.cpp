#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int convertAsciiToInteger(string &s);
int main()
{
	string s;
	cout << "Put in the ascii string to convert to integer ";
	cin >> s;
	int n = convertAsciiToInteger(s);
	cout << "Number converted is  " << n << endl;
}

int convertAsciiToInteger(string &s)
{
	int len = s.length();
	int number =0;
	if(len == 0 )
	{
		cout << "Empty string" << endl;
		exit(0);
	}
	bool neg =false;
	int lastIndex = 0;
	int multiplier = 0;
	if(s[0] == '-')
	{
		neg = true;
		lastIndex = 1;
		multiplier = -1;
	}
	else
	{
		multiplier = 1;
	}

	for(int i = len -1 ; i >= lastIndex ; i--)
	{
		if( s[i] < 48 || s[i] > 57 ) // not a digit;
		{
			cout << "Invalid character " << s[i] << " encountered. Exiting " << endl;
			exit(0);
		}
		number += (s[i] - 48)*multiplier;
		if(number < 0 && !neg || number > 0 && neg )
		{
			cout << "Overflow. Exiting " << endl;
			exit(0); 
		}
		multiplier = multiplier * 10;
	}
	return number;
}
