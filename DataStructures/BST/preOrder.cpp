#include <iostream>
#include "common/bst.h"
using namespace std;


void PreOrder(Node * n)
{
	if(n != NULL)
	{
		cout<< n->key << "  " ;
		PreOrder(n->left);
		PreOrder(n->right);
	}
}


int main()
{
Node * root = ConstructBST();
PreOrder(root);
}
