/*
 * BTreeNode.cpp
 *
 *  Created on: 01-Mar-2013
 *      Author: swati
 */

#include <iostream>
#include "BTreeNode.h"

using namespace std;


BTreeNode::BTreeNode()
{
	parent = NULL;
	leaf = false;
}

bool BTreeNode::isFull()
{
	if(!leaf)
	{
	if(childNodes.size() >= MAX_POINTERS)
	{
		return true;
	}
	return false;
	}
	else
	{
		if(keys.size() >= MAX_KEY)
		{
			return true;
		}
	}
return false;
}

bool BTreeNode::isLeaf()
{
	return leaf;
}


void BTreeNode::setLeaf(bool val)
{
leaf = val;
}

void BTreeNode::copyContent(BTreeNode * node , int startIndex , int endIndex)
{
	if(node->keys.size() < endIndex || startIndex < 0)
	{
		cerr << "Error Invalid copy attempted from Node" << endl;
		return;
	}
	for (int i = startIndex ; i <= endIndex ; i++ )
	{
	keys.push_back(node->keys[i]);
	if(leaf)
	data.push_back(node->data[i]);
	else
		this->childNodes.push_back(node->childNodes[i]);
	}
}


void BTreeNode::InsertIntoLeafNode(int key , int value)
{
	bool inserted = false;
	vector<int>::iterator it ,it2;
	for (it = keys.begin() , it2 = data.begin() ; it!=keys.end() ; it++ , it2++)
	{

		if( (*it) > key  )
		{
			keys.insert(it , key);
			data.insert(it2 , value);
			inserted = true;
			break;
		}
	}
	if(!inserted)
	{
		keys.push_back(key);
		data.push_back(value);
	}
}


void BTreeNode::insertIntoNode(int key , BTreeNode *left , BTreeNode *right )
{
	bool inserted = false;
	int count = 0;
	vector<int>::iterator it;
	vector<BTreeNode*>::iterator it2;
	for(it = keys.begin() , it2 = childNodes.begin(); it!= keys.end() ; it++ , it2++)
	{
		count++;
		if( (*it) > key  )
		{
			inserted = true;
			keys.insert(it , key);
			if(it == keys.begin())
			{
				childNodes.erase(it2);
				childNodes.insert(childNodes.begin() ,right);
				childNodes.insert(childNodes.begin() , left);
			}
			else
			{
				childNodes[count] = left;
				it2++;
				childNodes.insert(it2 , right);
			}
			break;
		}

	}
	if(!inserted)
	{
		keys.push_back(key);
		childNodes.back() = left;
		childNodes.push_back(right);
	}
	left->setParent(this);
	right->setParent(this);
}


bool BTreeNode::searchLeaf(int key)
{
	vector<int>::iterator it;
	for(it = keys.begin() ; it != keys.end() ; it++  )
	{
		if(*it == key )
		{
			return true;
		}
	}
	return false;
}


vector<BTreeNode*> & BTreeNode::getChidNodes()
{
	return childNodes;
}


vector<int>& BTreeNode::getkeys()
{
	return keys;
}


vector<int>& BTreeNode::getdata()
{
	return data;
}


BTreeNode* BTreeNode::getparent()
{
	return parent;
}


void BTreeNode::setParent(BTreeNode *p)
{
	parent = p;
}
