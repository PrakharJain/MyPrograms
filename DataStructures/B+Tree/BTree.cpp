#include "BTree.h"
#include "BTreeNode.h"
#include <iostream>
using namespace std;

BPlusTree::BPlusTree()
{
	root = NULL;
}
BTreeNode * BPlusTree::GetLeafNode(int key)
{
	BTreeNode * temp = root;
	while(temp!= NULL)
	{
		if(temp->isLeaf())
		{
			return temp;
		}
		else
		{
			bool found = false;
			for (unsigned int i = 0 ; i < temp->getkeys().size() ; i++)
			{
				if(key <= temp->getkeys()[i])
				{
					temp = temp->getChidNodes()[i];
					found = true;
					break;
				}
			}
			if(!found)
			{
				temp = temp->getChidNodes()[temp->getChidNodes().size() -1];
			}
		}
	}
	return NULL;
}


void BPlusTree::split(BTreeNode * node , int key , int value )
{
	// key should not be duplicate;
	// this method is only for leafnodes;
	int splitIndex = -1;
	node->InsertIntoLeafNode(key,value);
	splitIndex = node->getkeys().size()/2;
	BTreeNode * left = node;
	BTreeNode * right = new BTreeNode();
	right->setLeaf(true);
	int keyToElevate = node->getkeys()[splitIndex];
	right->copyContent(node , splitIndex +1 , node->getkeys().size()-1);
	node->getkeys().resize(splitIndex+1);
	if(node->getparent() == NULL )
	{
		root = new BTreeNode();
		root->getkeys().push_back(keyToElevate);
		root->getChidNodes().push_back(left);
		root->getChidNodes().push_back(right);
		left->setParent(root);
		right->setParent(root);
		return;
	}
	if(node->getparent()->isFull())
	{
		splitParent( node->getparent() , keyToElevate , left , right);
	}
	else
	{
		node->getparent()->insertIntoNode(keyToElevate , left , right);
	}
}


void BPlusTree::splitParent(BTreeNode * node , int key , BTreeNode * leftNode , BTreeNode * rightNode)
{
		if(node == NULL)
			{
				root = new BTreeNode();
				root->getkeys().push_back(key);
				root->getChidNodes().push_back(leftNode);
				root->getChidNodes().push_back(rightNode);
				return;
			}
		node->insertIntoNode(key , leftNode , rightNode);
		int splitIndex = node->getkeys().size()/2;


		BTreeNode * left = node;
		BTreeNode * right = new BTreeNode();
		int keyToElevate = node->getkeys()[splitIndex];
		right->copyContent(left , splitIndex+1 , node->getkeys().size()-1);
		left->getkeys().resize(splitIndex);
		left->getChidNodes().resize(splitIndex);

		if(node->getparent() == NULL || node->getparent()->isFull())
			splitParent(node->getparent() ,keyToElevate, left , right );
		else
		{
			node->insertIntoNode(keyToElevate , left , right);
			left->setParent(node);
			right->setParent(node);
		}
		return;
}



void BPlusTree::Insert(int key , int value)
{
	BTreeNode * node = GetLeafNode(key);
	if(node == NULL)
	{
		root = new BTreeNode();
		root->setLeaf(true);
		root->InsertIntoLeafNode(key ,value);
		return;

	}

	if(node->searchLeaf(key))
	{
		return;
	}
	if(node->isFull())
	{
		split(node ,key ,value);
	}
	else
	{
		node->InsertIntoLeafNode(key,value);
	}

}


void BPlusTree::PrintTree()
{
	PrintTree(root);
}

void BPlusTree::PrintTree(BTreeNode * node)
{
	if(node == NULL)
		return;
	vector<int>::iterator it;
	for(it = node->getkeys().begin() ; it != node->getkeys().end() ; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<BTreeNode*>::iterator it2;
	vector<BTreeNode*> &children = node->getChidNodes();
	//for(it2 = node->getChidNodes().begin(); it2 != node->getChidNodes().end() ; it2++)
	for(int i = 0 ; i < children.size() ; i++)
		PrintTree(node->getChidNodes()[i]);


}
