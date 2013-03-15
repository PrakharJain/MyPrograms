/* 
 * Below program converts al the lower case 'u' to uppercase 'U' without the ue of any if coditions.
 * This program was asked as part of interview for adap.tv
 */

#include <iostream>
using namespace std;

int Convert0(char * str);
int Convert( char * str);

int (*fun[2])(char*);

int Convert0(char * str)
{
	return 0;
}

int Convert(char * str)
{
	int a =str[0] ^ 'u'; // this will be 0 if the character is 'u' and greater tha 0 for any other character.
	bool b = a& 0xFF; // this will be 0  for 'u' and 1 for any other character.
	int c = b ^ 1; // this will flip the value of b. so if charcter is 'u' this will be 1 and 0 otherwise.

	str[0] = str[0] - c*32; // if charcter is 'u' c will be 1 and thus we will subtract 32 (this converts 'u' to 'U'). Otherwise c will be 0 				 // and str[0] will be assigned str[0] again.

	bool d  = str[0] && 0xFF;  // this calculation is doen to invoke correct version of covert. If we encounter '/0' character 
				   // we will invoke Convert0 which will return 0. Otherwise we cal Convert. This is used to stop the 
				  // recursion and return.
	int e = d;  // converting bool to int;

	return c*1 + fun[e](str+1);  // calling proper convert based on the value of index (represented by e).
}


int main()
{
	fun[0] = Convert0;
	fun[1] = Convert;
	char input[100];
	cout << "Please put in the string " ;
	cin >>input;
	int count = Convert(input);
	cout<< endl << "The converted string is " << input << endl << "No of changes " << count << endl;
	return 1;
}
