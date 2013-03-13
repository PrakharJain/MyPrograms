#ifndef TEMPLATE_BST_H
#define TEMPLATE_BST_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:

		Node()
		{
			left = NULL;
			right = NULL;
		}

		Node<T>* left;
		Node<T>* right;
		T key;
};

template <class T>
class BST
{
	public:
		void insert(T & value);
		bool find(T& value);
		BST();
	private:
		Node<T>* root;

};

#endif 
