#include "Utility.h"
#include "SingleLinkedList.h"
#include <iostream>
using namespace std;
SingleLinkedList* CreateSingleLinkedList()
{
	SingleLinkedList * list = new SingleLinkedList;
	int data;
	cout << " Please put in the elements of the Linked List -9999 to stop" << endl;
	cin >> data;
	while (data != -9999)
	{
		list->Insert(data);
		cin >> data;
	}
	return list;
}	
