#include <iostream>
#include "../DataStructures/BST/common/bst.h"
using namespace std;

void SumToLeaf(Node * root , int numTillNow , int& sum);
int SumTree(Node * root); 

int main()
{
	Node * root = ConstructBST();
	int sum = SumTree(root);
	cout << "The sum is " << sum << endl;
	return 0;
}

int SumTree(Node * root)
{
	int sum = 0 ;
	SumToLeaf(root,0 ,sum);
	return sum;
}


void SumToLeaf(Node* root , int numTillNow , int &sum)
{
	if(root == NULL)
		return;

	numTillNow = numTillNow * 10 + root->key;
	if(root->left == NULL && root->right == NULL)
	{
		sum = sum + numTillNow;
		return;
	};
	
	if(root->left)
		SumToLeaf(root->left , numTillNow , sum);

	if(root->right)
		SumToLeaf(root->right , numTillNow , sum);
} 
