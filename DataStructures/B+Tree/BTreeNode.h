#ifndef BTREE_NODE_H
#define BTREE_NODE_H
#include <vector>
using namespace std;


const unsigned int MAX_KEY = 2;
const unsigned int MAX_POINTERS = 3;
const unsigned int MIN_KEY = 1;
const unsigned int MIN_POINTERS = 2;
const unsigned int ORDER = MAX_POINTERS;

class BTreeNode
{
public:
	BTreeNode();
	bool isFull();
	bool isLeaf();
	void copyContent(BTreeNode * node , int startIndex , int endIndex);
	void setLeaf(bool val);
	void InsertIntoLeafNode(int key , int value);
	void insertIntoNode(int key , BTreeNode *left , BTreeNode *right );
	bool searchLeaf(int key);
	vector<BTreeNode*> & getChidNodes();
	vector<int>& getkeys();
	vector<int>& getdata();
	BTreeNode* getparent();
	void setParent(BTreeNode* p);
private:
	vector<BTreeNode*> childNodes;
	vector<int> keys;
	vector<int> data;
	BTreeNode* parent;
	bool leaf;
};

#endif
