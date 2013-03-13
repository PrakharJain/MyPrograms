#include "BTreeNode.h"
#include "BTree.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello";
	BPlusTree tree;
	tree.Insert(100,2);
	tree.Insert(12,5);
	tree.Insert(15,7);
	tree.Insert(18,9);
	tree.Insert(20 ,10);
	tree.Insert(25,19);
	tree.Insert(30 , 24);
	/*tree.Insert(45 , 24);
	tree.Insert(35 , 24);
	tree.Insert(8 , 24);
	tree.Insert(23 , 24);
	tree.Insert(33 , 24);
	tree.Insert(87 , 24);
	tree.Insert(64 , 24);
	tree.Insert(3 , 24);
	/*tree.Insert(53 ,1);
	tree.Insert(28 ,2);
	tree.Insert(86 ,3);
	tree.Insert(67 ,4);
	tree.Insert(40 ,5);
	tree.Insert(46 ,6);
	tree.Insert(75 ,7);
	tree.Insert(35 ,8);
	tree.Insert(101 ,9);
	tree.Insert(80 ,10);
	tree.Insert(125 ,11);
	tree.Insert(12 ,12);
	tree.Insert(88 ,13);*/
	tree.PrintTree();




}
