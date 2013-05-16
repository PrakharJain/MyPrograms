#include <iostream>
#include "common/bst.h"
using namespace std;


void Inorder(Node * n , int& count ,int k )
{
	if(n != NULL && count != k)
	{
		Inorder(n->left , count , k);
		count++;
		if(count == k )
			cout << k << "th value is " << n->key << endl;
		Inorder(n->right , count , k);
	}
}


int main()
{
Node * root = ConstructBST();
int k;
cout << "Put in the value of K " << endl;
cin >> k;
int count =0;
Inorder(root, count,  k);
}
