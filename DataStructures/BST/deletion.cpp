#include <iostream>
#include "common/bst.h"
using namespace std;


void Inorder(Node * n)
{
	if(n != NULL)
	{
		Inorder(n->left);
		cout <<  n->key << endl;
		Inorder(n->right);
	}
}


int main()
{
Node * root = ConstructBST();

int k;
cout << "Put in the key to be deleted" << endl;
cin >> k;
cout << "Tree is " ;
Inorder(root) ;
cout << endl;

Node * temp = Search(root , k);
Delete(root , temp);

cout << "After Deletion " ;
Inorder(root); 
cout  << endl;

}
