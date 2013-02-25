/*
 * trie.cpp
 *
 *  Created on: 19-Feb-2013
 *      Author: swati
 */

#include "trie.h"

Trie::Trie()
{
	root = new Node;
}

void Trie::insert(string &s)
{
	Node * current = root;
	for (int i = 0 ; i < s.length(); i++)
	{
		Node* temp = NULL;
		temp = find (current, s[i]);
		if(temp == NULL)
		{
			temp = new Node;
			temp->data = s[i];
			current->children.push_back(temp);
		}
		current = temp;
	}
	current->isWord = true;
}

Node * Trie::find(Node * current , char ch)
{
	Node * temp = NULL;
	int size = current->children.size();
	for(int i = 0 ; i < current->children.size() ; i++)
	{
		char c = current->children[i]->data;
		if(current->children[i]->data == ch)
		{
			temp = current->children[i];
			break;
		}
}
return temp;
}


bool Trie::find(string &s)
{
	Node * current  = root;
	int i =0;
	for(i = 0 ; i < s.length() ; i++)
	{
		Node * temp = 	find(current , s[i]);
		if(temp != NULL)
		{
			current = temp;
		}
		else
		{
			break;
		}
	}
	if(i == s.length() && current->isWord)
	{
		return true;
	}
	return false;
}
