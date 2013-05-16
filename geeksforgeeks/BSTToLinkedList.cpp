/*
 * Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). 
 * The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
 * The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
 * The first node of Inorder traversal (left most node in BT) must be head node of the DLL. Convert this BST inplace to doubly linked list.
 * http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 */

#include "../DataStructures/BST/common/bst.h"
#include <iostream>

Node * ConvertToLinkedList( Node * root , Node*& head); // here curren id the node being processed in the linked list and root is the current node being processed from the BST.

using namespace std;
void PrintLinkedList(Node * head)
{
	Node * temp = head;
	while(temp!=NULL)
	{
		cout << temp->key << "  ";
		temp = temp->right;
	}
}


main()
{
	Node * root = ConstructBST();
	Node * head = NULL;
	ConvertToLinkedList(root , head);
	PrintLinkedList(head);
}


Node * ConvertToLinkedList(Node * root , Node *& head )
{
	if(root == NULL)
	{	
		return NULL;
	}
	if(root->left == NULL && root->right == NULL)
	{
		if(head == NULL)
			head = root;
		return root;
	}
	else
	{
		if(root->left != NULL)
		{
			Node * prev = ConvertToLinkedList(root->left, head);
			prev->right = root;
			root->left = prev;
		}
		else
		{
			if(head == NULL)
			{
				head = root;
			}
		}

		if(root->right != NULL)
		{

			Node * temp   = ConvertToLinkedList(root->right , head);
			temp->left = root;
		}
	}
	return root;
}
