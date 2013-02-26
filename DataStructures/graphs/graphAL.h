#ifndef GRAPH_ADJACENCY_LIST
#define GRAPH_ADJACENCY_LIST

#include <iostream>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
using namespace std;

struct Vertex
{
	string id;
	vector< boost::shared_ptr<Vertex> > neighbours;
	Vertex() 
	{

	}

	Vertex(string& s):id(s)
	{

	}
};

class GraphAL
{
	public:
	void addEdge(string &id1  , string& id2);
	void BFS();
	void DFS();
	~GraphAL();
	const vector< boost::shared_ptr<Vertex> > & getNeighbours(string &id);
	const map <string , boost::shared_ptr<Vertex> > & getNodes();
	private:
	map< string , boost::shared_ptr<Vertex> > nodes;
};


#endif

