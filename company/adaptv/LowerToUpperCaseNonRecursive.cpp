/*
 * This program converts all the lower case 'u' to upper case 'U' in a non recursive manner.
 */

#include <iostream>
using namespace std;

int Convert( char * str)
{
	int i =0;
	int count =0;
	while(str[i] != '\0')
	{
		if(str[i] == 'u')
		{
			str[i] = 'U';
			count++;
		}
		i++;
	}
	return count;
}


int main()
{
	char input[100];
	cout << "Please enter the string " ;
	cin.getline(input, 100);
	int count = Convert(input);
	cout << " The string is " << input <<endl << " No of changes = " << count << endl;
}
