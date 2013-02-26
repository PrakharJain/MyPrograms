/*
Overview
In this assignment you will build a small, simple system to calculate distance and travel time
for routes. A route consists of an ordered sequence of roads, each of which has a name and
a length in miles. There are two kinds of roads: highways and streets. On streets, you can
always travel at 30 miles per hour. On highways, you can travel 65 miles per hour, but it
always takes at least 1 minute to drive on a highway, no matter how short it is.
For example, a route from the Adap.tv office to Stanford University consists of the following
sequence of roads:
● Norfolk Street (a street), for 0.5 miles.
● Hillsdale Boulevard (a street), for 0.2 miles.
● US-101 (a highway), for 10.2 miles.
● University Avenue (a street), for 2.6 miles.
File Format for Routes
When we encode a route in a file, each line represents a road and is of the form [street
name],[type],[length]. Each file contains one route. You may assume that street names
will never have embedded commas. The type is either H for highway or S for street. For
example, the file format of the route above is:
Norfolk Street,S,0.5
Hillsdale Boulevard,S,0.2
US-101,H,10.2
University Avenue,S,2.6
Your Challenge
Create a program in any language that reads the route from standard input and produces
output of the distance in miles and the time in hours of the route. In creating your program,
try to make it the best at some aspect of software engineering. Be sure to include instructions
and also a sample test case with your program. It should be easy for us to figure out how to
use it!
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Road
{
	string name;
	string type;
	float distance;
	Road()
	{
	distance = 0;
	}
};

struct RouteInfo
{
	RouteInfo()
	{
		distance = 0 ;
		time = 0;
	}
	float distance;
	float time;
};

class RouteHelper
{
public:
	RouteInfo& GetRouteSummary(char * filename);

private:

	void GetRoute(char *filename);
	void GetRouteInfo();
	RouteInfo info;
	vector<Road> roads;	
};


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cerr << "Improper invocation. " << endl << "Usage : executable inputfile" << endl;
		exit(0);
	}	
	RouteHelper helper;
	RouteInfo & info = helper.GetRouteSummary(argv[1]);
	cout << "The Distance is " << info.distance << " miles" <<  endl << "Time taken is " << info.time << " hours" << endl;
}

RouteInfo& RouteHelper::GetRouteSummary(char* filename)
{
	GetRoute(filename);
	GetRouteInfo();
	return info;
}

void RouteHelper::GetRoute(char *filename)
{

	fstream in(filename, fstream::in);
	string word;
	string line;

	while(getline(in, line ))
	{
		istringstream stream(line);
		vector<string> data;
		int j = 0;
		while( getline(stream, word, ',') )
		{
			data.push_back(word);
			j++;
		}
		if(j!=3)
		{
			cerr << "Error in input file" << endl;
			exit(0);
		}
		Road r;
		r.name = data[0];
		if(data[1] == "S" || data[1] == "H")
			{
			r.type = data[1];
			}
		else
			{
			cerr << "Error in input file " << endl;
			exit(0);
			}
		r.distance = atof(data[2].c_str());
		roads.push_back(r);
	}
	in.close();
}


void RouteHelper::GetRouteInfo()
{
	for(int i = 0 ; i < roads.size(); i++)
	{
		info.distance+=roads[i].distance; 
		float time = 0; 
		if(roads[i].type == "H")
		{
			 
			time = roads[i].distance* 60 / 65;
		
			if(time < 1.0 )
			{
				
				info.time += 1.0;
			}
			else
			{
			info.time += time;
			}	
		
		}
		else
			{
				time = roads[i].distance * 60 / 35;
				info.time += time;
			}
	}
	info.time /=60.0;
}
