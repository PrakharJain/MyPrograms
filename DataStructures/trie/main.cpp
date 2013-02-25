/*
 * main.cpp
 *
 *  Created on: 19-Feb-2013
 *      Author: swati
 */

#include "trie.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << " No of command line args is " << argc;
	cout << endl << "command line argument is " << argv[0];

	fstream in(argv[1], fstream::in);
	string word;
	cout << endl;
	Trie t;
	while(in.good())
	{
		in >> word;
		t.insert(word);
		cout << "Word is " << word << endl;
	}
	in.close();
	string str("hello");
	if(t.find(str))
	{
		cout << "Found " << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
}
