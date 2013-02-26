#include <stdexcept>
#include "graphAL.h"

void GraphAL::addEdge(string& id1 , string& id2)
{
	nodeptr& node1 = nodes[id1];
	nodeptr& node2 = nodes[id2];
	node1->neighbours.push_back(node2);
	node2->neighbours.push_back(node1);	
}


const vector< nodeptr >& GraphAL::getNeighbours(string &id)
{
	boost::shared_ptr<Vertex>&node = nodes[id];
	return node->neighbours;
}


const map <string , nodeptr > & GraphAL::getNodes()
{
	return nodes;
}

void GraphAL::printGraph()
{
	for( map<string , nodeptr >::iterator it = nodes.begin(); it != nodes.end() ; it++)
	{
		cout << "Node " << it->first << "is conected to ";
		vector< nodeptr >& neighbours = it->second->neighbours;
		for(vector< nodeptr >::iterator n = neighbours.begin() ; n!= neighbours.end() ; n++)
		{
		cout << (*n)->id << " " ;
		}
	}
}

