#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void ReplaceWords (char * text , char * pat , char * newpat);

/* whole word will match only if the whole word is present alone.
 * example:  search for bad in hyderabad will yield zero with whole word set to true and 1 with whole word set to false
 */
void GetCountAndIndex(char * text , char * pat , int * arr , int &count, bool wholeword = false);
void ShiftLeftAndReplace (char * text , char * pat , char * newpat);
void ShiftRightAndReplace (char * text , char * pat , char * newpat);


int main()
{

	char text[1024];
	char pat[30];
	char newpat[30];

	cout << "Please put in the text " << endl;
	cin.getline(text ,1024);

	cout << "Put in the pattern to replace " << endl;
	cin.getline(pat , 30);

	cout << " Put in the new pattern " << endl;
	cin.getline(newpat,30);

	ReplaceWords(text , pat , newpat);
	cout << "New text is " << text << endl;

}


void ReplaceWords(char * text , char * pat , char * newpat)
{
	int patlen = strlen(pat);
	int newpatlen = strlen(newpat);

	if(patlen > newpatlen )
		ShiftLeftAndReplace(text,pat,newpat);
	else
		ShiftRightAndReplace(text,pat,newpat);
}


void ShiftRightAndReplace (char * text , char * pat , char * newpat)
{
		
	cout << " Inside Right shift " << endl;
	int count = 0;
	int arr[20];
	GetCountAndIndex(text,pat, arr ,count,true);
	cout << "Count is " << count << endl;
	cout << "Indexes are " << endl;
	for(int i = 0 ;  i< count ; i ++)
	{
		cout << arr[i] << endl;
	}
	int textlen  = strlen(text);
	int patlen = strlen(pat);
	int newpatlen = strlen(newpat);
	int shift = newpatlen - patlen;
	int i = textlen -1;
	int newlength = textlen + shift*count;
	cout << "New length is " << newlength << endl;
	text[newlength] = '\0';
	while(i!=0)
	{
		if(i > arr[count-1]  )
		 {
		 cout << "i+ shift = "<< i+shift*count << endl;
		   text[i+count*shift] = text[i];
		 }
		else
		{
		if(i == arr[count-1] )
			{
			cout << "i = " << i << endl;
			for(int j = 0 ; j < newpatlen ; j++)
				{
				text[i+j + (count-1) * shift] = newpat[j]; // here we need to consder move for the remaining pat as well. and so shift*(count-1) is also added to the new location of the text.
				}
			count--;
			}
		}
		i--;
	}
}

void ShiftLeftAndReplace(char * text , char * pat , char * newpat)
{

	int count = 0;
	int arr[20];
	GetCountAndIndex(text,pat, arr , count);
	cout << "Count is " << count << endl;
	cout << "Indexes are " << endl;
	for(int i = 0 ;  i< count ; i ++)
	{
		cout << arr[i] << endl;
	}


	int textlen  = strlen(text);
	int patlen = strlen(pat);
	int newpatlen = strlen(newpat);

	int shift = patlen - newpatlen;
	int i = 0;
	int newlength = textlen + shift*count;
	cout << "New length is " << newlength << endl;
	text[newlength] = '\0';
	int index = 0;
	while(text[i]!='\0')
	{
		if(i < arr[index]  )
		{
			cout << "i+ shift = "<< i+shift*count << endl;
			text[i-index*shift] = text[i];
			i++;
		}
		else
		{
			if(i == arr[index] )
			{
				cout << "i = " << i << endl;
				for(int j = 0 ; j < newpatlen ; j++)
				{
					text[i+j + (index * shift)] = newpat[j]; // here we need to consder move for the remaining pat as well. and so shift*(count-1) is also added to the new location of the text.
				}
				index++;
			}
		i = i + patlen;
		}
		
	}

}

void GetCountAndIndex(char * text , char * pat , int * arr , int & count , bool wholeword)
{
	count = 0;
	int patlen =  strlen(pat);
	char * temp = text;
	while((temp = strstr(temp , pat)) != NULL)
	{
		if(wholeword)
		{
			if( (temp == text || (*(temp -1) == ' ') ) && ( *(temp+patlen) == ' ' || *(temp+patlen) == '.' || *(temp+patlen) == '\0') )

			{
				arr[count] = temp - text; 
				count++;
			}
		}
		else
		{
			arr[count] = temp - text;
			count++;
		}

		temp = temp +  patlen;
	}
}

