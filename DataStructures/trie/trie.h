/*
 * trie.h
 *
 *  Created on: 19-Feb-2013
 *      Author: swati
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	vector<Node *> children;
	char data;
	bool isWord;
	string word;
};
class Trie
{
public:
	void insert(string &s);
	Trie();
	Node * find(Node* current , char ch );
	bool find(string &s);
private:
	Node * root;
};


#endif /* TRIE_H_ */
