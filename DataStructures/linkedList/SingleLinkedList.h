#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <iostream>
#include "Node.h"

class SingleLinkedList
{
	public:

		Node * Insert(int data);
		int Delete(Node * nodeToDel , Node * prev);
		void RemoveDuplicates();
		Node * findNthLastElement(int n);
		void Print();
		SingleLinkedList();
		~SingleLinkedList();
		void Reverse();
	private:

		void RemoveDuplicates(Node * head);
		Node * head;
};

#endif
