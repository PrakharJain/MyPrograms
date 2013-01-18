#ifndef RBNODE_H
#define RBNODE_H

#include <iostream>


enum Color
{
	None,
	Red,
	Black
};

class rbnode
{
	public:

		rbnode * parent;
		rbnode * left;
		rbnode * right;
		int data;
		Color c;

		rbnode()
		{
			parent = NULL;
			left = NULL;
			right = NULL;
			c = None;
			data = -9999;
		}
};

#endif
