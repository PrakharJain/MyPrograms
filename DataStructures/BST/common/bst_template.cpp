#include <iostream>
#include "bst_template.h"
using namespace std;

template <class T> BST<T>::BST()
{
	root = NULL;
}

template<class T> bool BST<T>::find(T& value)
{
	Node<T>* temp = root;
	while(temp!=NULL)
	{
		cout << "Reached here " << endl;
		if(temp->key ==  value)
		{
			return true;		
		}
		else if(temp->key < value)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return false;
}


template<class T> void BST<T>::insert (T& data)
{
	Node<T>* temp = root;
	Node<T>* parent = NULL;
        if(root == NULL)
        {
        temp = new Node<T>();
        temp->key = data;
	root = temp;
	return;
        }

	while(temp != NULL)
	{
		parent = temp;
		if(data == temp->key)
		{
			return;
		}
		else if(data < temp->key)
		{

			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	temp = new Node<T>();
	temp->key = data;
	if(parent != NULL)
	{ 
		if(data < parent->key)
		{
			parent->left = temp;
		}
		else
		{
			parent->right = temp;
		}
	}
}


int main()
{
	BST<int> tree;
	int val = 10;
	tree.insert(val);
	if(tree.find(val))
		{
		cout << "Found  " << val << endl;
		}
}
