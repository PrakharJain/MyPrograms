#ifndef BPLUSTREE_H
#define BPLUSTREE_H

class BTreeNode;

class BPlusTree
{

public:
	void Insert(int key , int value);
	BPlusTree();
	void PrintTree();

private:
	void PrintTree(BTreeNode * node);
	void split(BTreeNode * node , int key , int value );
    BTreeNode * GetLeafNode(int key); // returns the address of the leaf node where the key-value may be found;
    BTreeNode * root;
    void splitParent(BTreeNode * node , int key , BTreeNode * leftNode , BTreeNode * rightNode);
};


#endif
