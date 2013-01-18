#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include<iostream>
#include "rbnode.h"

class RedBlackTree
{

	public:
		rbnode * Insert(int data);
		RedBlackTree();


	private:
		void RotateLeft(rbnode * x);
		void RotateRight(rbnode * x);


		rbnode * root;
};
#endif
