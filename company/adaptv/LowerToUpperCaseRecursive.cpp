/*
 * This program converts all the lower case 'u' to upper case 'U' in a recursive manner.
 */
#include <iostream>
using namespace std;

int Convert(char * str)
{
if(str[0] != '\0')
    {
      if(str[0] == 'u')
          {
              str[0] = 'U';
              return 1+Convert(str+1);
          }
       else
       {
          return Convert(str+1);
       }
    }
return 0;
}



int main()
{
        char input[100];
        cout << "Please enter the string " ;
        cin.getline(input, 100);
        int count = Convert(input);
        cout << " The string is " << input <<endl << " No of changes = " << count << endl;
}

