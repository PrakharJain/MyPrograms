#include <stdexcept>
#include "graphAL.h"

/*

Graph structure
a --- c
a --- d
a --- e
b --- f
b --- e
c --- f
c --- d
e --- f
g --- h
g --- j
j --- i
i --- h

 */
void GraphAL::constructGraph()
{
	string a = "a";
	string b = "b";
	string c = "c";
	string d = "d";
	string e = "e";
	string f = "f";
	string g = "g";
	string h = "h";
	string i = "i";
	string j = "j";
	addEdge(a , c);
	addEdge(a , d);
	addEdge(a , e);
	addEdge(b , f);
	addEdge(b , e);
	addEdge(c , f);
	addEdge(c , d);
	addEdge(e , f);
	addEdge(g , h);
	addEdge(g , j);
	addEdge(j , i);
	addEdge(i , h);
}

void GraphAL::addEdge(string& id1 , string& id2)
{
	nodeptr& node1 = nodes[id1];
	if (node1.get() == NULL)
	{
	nodeptr n1 (new Vertex(id1));
	node1 = n1;
	}
	nodeptr& node2 = nodes[id2];
	if(node2.get() == NULL)
	{
	nodeptr n2(new Vertex(id2));
	node2 = n2;
	}
	node1->neighbours.push_back(node2);
	node2->neighbours.push_back(node1);	
	cout << "Iserted " <<id1 << "---" << id2 << endl;
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
		cout << "Node " << it->first << " is conected to ";
		vector< nodeptr >& neighbours = it->second->neighbours;
		for(vector< nodeptr >::iterator n = neighbours.begin() ; n!= neighbours.end() ; n++)
		{
		cout << (*n)->id << " " ;
		}
		cout << endl;
	}
}

GraphAL::~GraphAL()
{
}
