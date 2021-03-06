#include <iostream>
#include "bst.h"
using namespace std;

Node * ConstructBST()  // creates a BST and returns the pointer to its root node;
{
	cout << __FUNCTION__ << endl;
	Node * root = NULL;
	int data = 0;
	cout << "Enter the elements of BST -9999 to stop" << endl;
	cin >> data;
	if(data == -9999)
	{
		return root;
	}

	root = BstInsert(root , data);
	cin >> data;
	while(data != -9999)
	{
		BstInsert(root , data);
		cin >> data;
	}
	return root;
}


Node * BstInsert(Node * root , int data) // this method returns the pointer to the newly constructed Node
{
	cout << __FUNCTION__ << endl;
	cout << "BstInsert entered" << endl;
	Node* temp = root;
	Node * parent = NULL;
	if(temp == NULL)
	{
	temp = new Node();
		temp->key = data;
		root = temp;
	}
	else 
	{
		while(temp != NULL)
		{
			parent = temp;
			if(data <= temp->key)
			{
			
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		
		temp = new Node();
		temp->key = data;
		// assign parent to the child
		temp->parent = parent;
		// assign the child to the parent determine left or right child 
		if(data <= parent->key)
		{
			parent->left = temp;
		}
		else
		{
			parent->right = temp;
		}

	}
	cout << "Returning " << endl;
	return temp;
}

Node * BstInsertRecursive(Node * n , int data)
{
	cout << __FUNCTION__ << endl;
	Node * temp = NULL;
	if (n == NULL)
	{
		temp = new Node();
		temp->key = data;

	}

	if( data <=  n->key)
	{
		if(n->left != NULL)
		{
			BstInsertRecursive(n->left , data);
		}
		else
		{
			temp = new Node();
			temp->key = data;
			temp->parent = n;
			n->left = temp;
			// insert the left child here
		}
	}
	else
	{
		if(n->right != NULL)
		{
			BstInsertRecursive(n->right , data);
		}
		else
		{
			temp = new Node();
			temp->key = data;
			temp->parent = n;
			n->right = temp;
			// insert the right child here
		}
	}
	return temp;
}

Node * Search(Node * root , int searchKey)
{
	cout << __FUNCTION__ << endl;
	Node * temp = NULL;
	temp = root;
	while (temp != NULL)
	{
		if(searchKey == temp->key)
		{
			break;
		}
		else
		{
			if(searchKey < temp->key)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
	return temp;
}

Node * MinimumNode( Node * root)
{
	cout << __FUNCTION__ << endl;
	if(root == NULL)
		return NULL;
	Node * temp = root;
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

Node * MaximumNode(Node * root)
{
	cout << __FUNCTION__ << endl;
	if(root == NULL)
		return NULL;
	Node * temp = root;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

Node * Successor( Node * root)
{
	cout << __FUNCTION__ << endl;
	if(root->right != NULL)
	{
		return MinimumNode(root->right);
	}
	Node * x = root;
	Node * y = root->parent;
	while(y != NULL && y->right == 	x)
	{
		x = y;
		y = x->parent;
	}
	return y;
}

void Transplant (Node*& root , Node* oldNode , Node * newNode)
{
	cout << __FUNCTION__ << endl;
	if(oldNode->parent == NULL)
	{
		
		root = newNode;
		newNode->parent = NULL;
	}
	else
	{
		if(oldNode->parent->left == oldNode)
		{
			oldNode->parent->left = newNode;
		}
		else
		{
			oldNode->parent->right = newNode;
		}
		if(newNode!=NULL)
		{
			newNode->parent = oldNode->parent;
		}	
	}
}

void Delete(Node*&root ,  Node * n)
{
	cout << __FUNCTION__ << endl;
	if(n->left == NULL)
	{
		Transplant(root, n , n->right);
	}
	else if(n->right == NULL)
	{
		Transplant(root , n , n->left);
	}
	else
	{
		Node * temp = MinimumNode(n->right);
		if(temp->parent != n)
		{
			Transplant(root , temp , temp->right);
			temp->right = n->right;
			temp->right->parent = temp;
		}
		Transplant(root , n , temp);
		temp->left = n->left;
		temp->left->parent = temp;
	}
	delete n;
}

