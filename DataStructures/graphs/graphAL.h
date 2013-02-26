#ifndef GRAPH_ADJACENCY_LIST
#define GRAPH_ADJACENCY_LIST

#include <iostream>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
using namespace std;
struct Vertex;
typedef boost::shared_ptr<Vertex> nodeptr;

struct Vertex
{
	string id;
	vector< nodeptr > neighbours;
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
		const vector < nodeptr >& getNeighbours(string &id);
		const map <string , nodeptr > & getNodes();
		void printGraph();
		void constructGraph();
	private:
		map< string , nodeptr > nodes;
};


#endif

