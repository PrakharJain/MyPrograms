#include <iostream>
#include <string>
using namespace std;

int * FillShiftTable(const string &str )
{
	int * shiftTable = new int[256];
	int len = str.length();
	for(int j = 0; j < 256 ; j++)
	{
		shiftTable[j] = len;
	}
	for(int i = 0 ; i <len ; i++)
	{
		shiftTable[str[i]] = (len-1) -i;
	}
	return shiftTable;
}


int Horspool (const string & text , const string &str)
{
	int * shiftTable = FillShiftTable(str);
	int textLen = text.length();
	int strLen = str.length();
	int i = strLen -1;

	while ( i < textLen)
	{
		int k = strLen -1 ;
		while( str[k] == text[i] && k >=0)
		{
			k--;
			i--;
		}
		cout <<  "K = " << k << endl; 
		if( k<0)
		{
			// we found he match;
			return i+1;
		}
		else
		{
			// we did not find the match
			i = i+ shiftTable[text[i]];
		}
	}
	return -1;
}

int main()
{
	string text , str;
	cout << "Enter the text " << endl;
	cin >> text;
	cout << " Enter the string to match " << endl;
	cin >> str;
	int loc = Horspool(text,str);
	if(loc == -1)
	{
		cout << "No match found" << endl;
	}
	else
	{
		cout << "Match found at " <<loc << endl;
	}
	return 0;
}
