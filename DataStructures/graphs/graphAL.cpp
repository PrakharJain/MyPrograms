#include <stdexcept>
#include "graphAL.h"

void GraphAL::addEdge(string& id1 , string& id2)
{
	boost::shared_ptr<Vertex> & node1 = nodes[id1];
	boost::shared_ptr<Vertex>& node2 = nodes[id2];
	node1->neighbours.push_back(node2);
	node2->neighbours.push_back(node1);	
}


const vector<boost::shared_ptr <Vertex> >& GraphAL::getNeighbours(string &id)
{
	boost::shared_ptr<Vertex>&node = nodes[id];
	return node->neighbours;
}


const map <string , boost::shared_ptr<Vertex> > & GraphAL::getNodes()
{
	return nodes;
}
