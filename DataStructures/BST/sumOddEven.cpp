/*
 * Write a program to find the difference between the sum of nodes at odd height and the sum of nodes at even height
 */

#include <iostream>
#include "common\bst.h"



using namespace std;
void OddEvenSum(Node * root);
void Sum(Node * root , long& oddSum , long &evenSum , int level);

int main()
{
	Node * root = ConstructBST();
	OddEvenSum(root);
}


void OddEvenSum(Node * root)
{
	int level = 0;
	long oddSum = 0;
	long evenSum = 0;
	Sum(root,oddSum , evenSum , level);
	cout << "Even sum = " << evenSum << "Odd sum = " << oddSum << endl;
}



void Sum(Node * root , long &o, long &e ,int level)
{
	cout << "Level = " << level << endl;
	if(root == NULL)
	{
		return;
	}
	if(level % 2 == 0)
	{
		e+=root->key;
	}
	else
	{
		cout << "Entered else" << endl;
		o+=root->key;
		cout << "o = " << o << endl;
	}

	level++;
	Sum(root->left , o , e , level);
	Sum(root->right , o, e , level);
}
