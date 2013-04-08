/*
 * Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). 
 * The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
 * The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
 * The first node of Inorder traversal (left most node in BT) must be head node of the DLL. Convert this BST inplace to doubly linked list.
 * http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 */

#include "common/bst.h"
#include <iostream>

using namespace std;

struct LLInfo
{
	Node * last;
	Node * first;
};

LLInfo ConvertToLinkedList(Node * root);
LLInfo Convert(Node * root);
void PrintLinkedList(Node * head);

int main()
{
	Node * root = ConstructBST();
	LLInfo head = ConvertToLinkedList(root);
	cout << "First : " << head.first->key << endl;
	cout << "Last  : " << head.last->key << endl;
	PrintLinkedList(head.first);
}



LLInfo ConvertToLinkedList(Node* root)
{
	Node * head = NULL;
	LLInfo list = Convert(root);
	return list;
}


LLInfo Convert(Node * root)
{
	LLInfo list;
	if(root == NULL)
	{
		list.first =  NULL;
		list.last = NULL;
		return list;
	}
	LLInfo left = Convert(root->left);
	LLInfo right = Convert(root->right);
	if(left.last!=NULL)
	{
		root->left = left.last;
		left.last->right = root;
		list.first = left.first;
	}
	else
	{
		list.first = root;
	}

	if(right.first != NULL)
	{
		root->right = right.first;
		right.first->left = root;
		list.last = right.last; 
	}
	else
	{
		list.last = root;
	}

	return list;
}

void PrintLinkedList(Node * head)
{
	Node * temp = head;
	while(temp!=NULL)
	{
		cout << temp->key << "  ";
		temp = temp->right;
	}
}
