#include <iostream>
#include "RedBlackTree.h"


RedBlackTree::RedBlackTree()
{
	root = NULL;
}


rbnode * RedBlackTree::Insert(int data)
{

}


void RedBlackTree::RotateLeft(rbnode * x)
{

	rbnode * y =  x->right;
	x->right  =  y->left;
	if(y -> left != NULL)
	{
		y->left->parent = x;
	}
	if( x->parent =  NULL)
	{
		root = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right =  y;
	}

	y->left = x;
	x->parent = y;
}

void RedBlackTree::RotateRight(rbnode * x)
{

	rbnode * y = x->left;
	x->left = y->right;

	if(y->right != NULL)
	{
		y->right->parent = x;
	}

	if(x->parent = NULL)
	{
		root = y;
	}
	else if( x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

