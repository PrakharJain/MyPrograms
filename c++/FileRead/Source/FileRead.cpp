/*
 * FileRead.cpp
 *
 *  Created on: 19-Feb-2013
 *      Author: swati
 */

#include <iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << " No of command line args is " << argc;
	cout << endl << "command line argument is " << argv[0];

	fstream in(argv[1], fstream::in);
	string word;
	cout << endl;

	while(in.good())
	{
		in >> word;
		cout << "Word is " << word << endl;
	}
	in.close();
}
