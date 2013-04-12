#include "SingleLinkedList.h"
#include "Utility.h"
#include <iostream>
using namespace std;

void nthLast(SingleLinkedList*& list)
{
	cout << "Put in the value of n " << endl;
	int n;
	cin >> n;

	Node * node = list->findNthLastElement(n);
	if(node == NULL)
	{
		cout << n << "th element does not exist " << endl;
	}
	else
	{
		cout << n << "th element is "<<node->data << endl;
	}

}

void ReverseLinkedList(SingleLinkedList*& list)
{
list->Reverse();
cout << "Reversed List is " << endl;
list->Print();
}

int main()
{
SingleLinkedList * list = CreateSingleLinkedList();
cout << "Original List is " << endl;
	list->Print();
//nthLast(list);
ReverseLinkedList(list);
}


