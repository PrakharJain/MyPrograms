#include <stdexcept>
#include "graphAL.h"
#include<queue>
using namespace std;
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
	addUndirectedEdge(a , c);
	addUndirectedEdge(a , d);
	addUndirectedEdge(a , e);
	addUndirectedEdge(b , f);
	addUndirectedEdge(b , e);
	addUndirectedEdge(c , f);
	addUndirectedEdge(c , d);
	addUndirectedEdge(e , f);
	addUndirectedEdge(g , h);
	addUndirectedEdge(g , j);
	addUndirectedEdge(j , i);
	addUndirectedEdge(i , h);
}

void GraphAL::addUndirectedEdge(string& id1 , string& id2)
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
	cout << "Inserted " <<id1 << "---" << id2 << endl;
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


void GraphAL::DFS()
{
	cout << endl << "DFS traversal : " << endl;
	Reset();
	for(map<string, nodeptr>::iterator it = nodes.begin() ; it!=nodes.end() ; it++)
	{
		if(!(it->second->visited))
		{
			dfs(it->second);
		} 
	}
}


void GraphAL::dfs(nodeptr & nptr)
{
nptr->visited = true;
vector< nodeptr >& neighbours = nptr->neighbours;
for(vector< nodeptr >::iterator n = neighbours.begin() ; n!= neighbours.end() ; n++)
                {
		if(!(*n)->visited)
               	 dfs((*n));
                }
cout << nptr->id << " ";
}


void GraphAL::Reset()
{
	for(map<string, nodeptr>::iterator it = nodes.begin() ; it!=nodes.end() ; it++)
	{
		it->second->visited = false;
		it->second->visitOrder = 0;
        	it->second->popOrder = 0;
	}
}


void GraphAL::BFS()
{
	cout << endl << "BFS traversal " << endl;
        Reset();
        for(map<string, nodeptr>::iterator it = nodes.begin() ; it!=nodes.end() ; it++)
        {
                if(!(it->second->visited))
                {
                        bfs(it->second);
                }
        }
}

void GraphAL::bfs(nodeptr &nptr)
{
	nptr->visited = true;
	queue<nodeptr> q;
	q.push(nptr);

	while(!q.empty())
	{
		nodeptr &ptr = q.front();
		q.pop();
		vector< nodeptr >& neighbours = ptr->neighbours;
		for(vector< nodeptr >::iterator n = neighbours.begin() ; n!= neighbours.end() ; n++)
		{
			if(!(*n)->visited)
			{
				(*n)->visited = true;
				q.push((*n));
			}
		}
		cout << ptr->id << " ";
	}
}
