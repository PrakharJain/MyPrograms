#include <iostream>
#include "common/bst.h"
using namespace std;


void Inorder(Node * n)
{
	if(n != NULL)
	{
		Inorder(n->left);
		cout<< n->key << "  " ;
		Inorder(n->right);
	}
}


int main()
{
Node * root = ConstructBST();
Inorder(root);
}
