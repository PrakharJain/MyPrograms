#include <iostream>
#include "common/bst.h"


int Height(Node *root);
int Max(int a , int b);
int main()
{
Node * root = ConstructBST();
int h = Height(root);
cout << "Height of the tree is " << h << endl;
}

int Height(Node * root)
{
if(root == NULL)
	return 0;
return 1 + Max(Height(root->left) , Height(root->right));
}


int Max(int a , int b)
{
return a>=b?a:b;
}
