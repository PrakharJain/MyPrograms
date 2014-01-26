// The foloowing program remove 'a' and "bc" from a string 


#include<iostream>
#include<string>
using namespace std;

void RemoveFromString(char *str)
{
	int i =0;
	int shift = 0;
	while(str[i] != '\0')
	{
		if(str[i] == 'a')
		{
			shift++;
			i++;
		}
		else if(str[i] == 'b' && str[i+1] == 'c')
		{
			shift+=2;
			i+=2;
		}
		else
		{
			str[i-shift] = str[i];
			i++;
		}
		
	}
	str[i-shift] = '\0';
}


int main()
{
	char str[100];
	cout <<  "Please put in the string " << endl;
	cin.getline( str , 100) ;

	RemoveFromString(str);
	cout << " The modified string is " << endl;
	cout << str;
}

