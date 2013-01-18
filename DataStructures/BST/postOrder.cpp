#include <iostream>
#include "common/bst.h"
using namespace std;


void PostOrder(Node * n)
{
	if(n != NULL)
	{
		PostOrder(n->left);
		PostOrder(n->right);
		cout<< n->key << "  " ;
	}
}


int main()
{
Node * root = ConstructBST();
PostOrder(root);
}
