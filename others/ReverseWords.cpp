/*
Reverse words in a string
Ex:
Input : "This is a String"
Output: "String a is This"
*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


void ReverseWords(char * str )
{
	int length = strlen(str);
	int first , last;
	first = length;
	last = length -1;
	int index = 0;
	char * newstr = new char[length];
	newstr[length] = '\0';
	for (int i = length -1 ;i >=0 ; i--)
	{
		if(str[i] != ' ')
		{
		first--;
		}
			if(str[i] == ' ' || i == 0)
			{
				for(int j = first ; j <=last ; j++)
				{
					newstr[index++] = str[j];
				}
				if(index != length)
				{
					newstr[index++] = ' ';
					first --;
					last = first-1;
				}
				
			}
	}
strcpy(str , newstr);
}


int main()
{

	char str[200];
	cout << "Please put in the string " << endl;
	cin.getline(str , 200);
	cout << "Line read is " << str;
	ReverseWords(str);
	cout << "The reversed string is " << endl <<str << endl;
}

