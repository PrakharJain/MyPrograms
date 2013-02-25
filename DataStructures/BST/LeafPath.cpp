#include <iostream>
#include  "common/bst.h"
using namespace std;

void LeafPath(Node * root ,  int * arr , int level);
void PrintPath(int * arr , int index);

int main()
{
	Node * root = ConstructBST();
	int array[100];
	LeafPath(root,array,0);
}


void LeafPath(Node * root , int * arr , int level)
{

	if(root == NULL)
		{
	//	PrintPath(arr , level-1);
		return;
		}
	arr[level] = root->key;
	if(root->left != NULL)
		LeafPath(root->left , arr , level +1);
	if(root->right != NULL)
		LeafPath(root->right , arr, level +1);
	if(root->right == NULL && root->left == NULL)
		PrintPath(arr,level);
}


void PrintPath(int *arr , int index)
{
	if(index < 0)
		return;
	for(int i = 0 ; i <=index ; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}


