#include <iostream>
using namespace std;



class Node
{
	public:

		Node()
		{
			left = NULL;
			right = NULL;
			parent = NULL;
			key = -9999;
		}

		Node * left;
		Node * right;
		Node * parent;
		int key;
};


Node * ConstructBST();  // creates a BST and returns the pointer to its root node;
Node * BstInsert(Node * root , int data); // this method returns the pointer to the newly constructed Node
Node * BstInsertRecursive(Node * n , int data);
Node * Search(Node * root , int searchKey);
