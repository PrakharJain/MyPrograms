#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

SingleLinkedList::SingleLinkedList()
{
	head = NULL;
}

SingleLinkedList::~SingleLinkedList()
{
	while( head != NULL)
	{
		Node * temp = head;
		head = head->next;
		delete temp;
	}
}

Node * SingleLinkedList:: Insert(int data)
{
	Node * node =  NULL;
	if(head == NULL)
	{
		node = new Node();
		node-> data = data;
		head = node;
	}
	else
	{
		Node * temp = head;
		Node * prev = NULL;
		while (temp != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		node = new Node();
		prev->next = node;
		prev->next->data = data;
	}
	return node;
}

int SingleLinkedList::Delete(Node * nodeToDel , Node * prev)
{
	if (nodeToDel == NULL)
		return -9999;

	int data = nodeToDel->data;
	if( prev == NULL) // nodeToDel is same as head
	{
		head = nodeToDel->next;
	}
	else
	{
		prev->next = nodeToDel->next;
	}
	delete nodeToDel;
	return data;
}	

void SingleLinkedList::RemoveDuplicates(Node * head)
{
	if (head == NULL)
		return;
	Node * outer = head;
	while(outer != NULL)
	{
		Node * inner = outer->next;
		Node * prev = outer;
		while(inner != NULL)
		{
			if(outer->data == inner->data)
			{
				Node * temp = inner;
				prev->next = inner->next;
				inner = inner->next;
				delete temp;
			}
			else
			{
				prev = inner;
				inner = inner->next;
			}
		}
		outer = outer->next;
	}
}

void SingleLinkedList::Print()
{
	if(head == NULL)
	{
		cout << "List is empty " << endl;
	}
	else
	{
		cout << "The List is : " ;
		Node * temp = head;
		while(temp!= NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	cout << endl;
}

void SingleLinkedList::RemoveDuplicates()
{
	RemoveDuplicates(head);
}

Node * SingleLinkedList::findNthLastElement(int n)
{
	int count = 1;
	Node * temp = head;

	while ((count <= n-1) && (temp != NULL))
	{
		cout << "Count = " << count << endl;
		count++;
		temp = temp->next;
	}
	cout << "Count = " << count << endl;
	if (count <= n-1)
	{
		return NULL;
	}

	Node * temp2 = head;
	if(count == n && temp == NULL)  // boundry condition when the value of  entered is 1 more than the no of elements in the list
	{
		return NULL;
	}
	while(true)
	{
		temp =  temp->next;
		if(temp ==  NULL)
		{
			break;
		}
		temp2 = temp2->next;
	}
	return temp2;
}

void SingleLinkedList::Reverse()
{
	if(head == NULL || head->next == NULL)
		return;
	Node * current =  head->next;
	head->next = NULL;
	Node * prev = head;

	while(current != NULL)
	{
		Node * next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
