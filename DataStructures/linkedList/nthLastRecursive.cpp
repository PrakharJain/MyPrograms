#include "SingleLinkedList.h"
#include "Utility.h"
#include <iostream>
using namespace std;


int main()
{
	SingleLinkedList * list = CreateSingleLinkedList();
	list->Print();
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
