#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<iterator>

struct Edge {
	int DestinationVertexID;
	int Weight;
	Edge() = default;
	Edge(int destVID, int weight) :
		DestinationVertexID(destVID),Weight(weight)
	{

	}
};

class Vertex {
public:
	int StateID =0;
	std::string StateName ="";
	std::list<Edge> EdgeList;

	Vertex(int id, const std::string& name) :
	StateID(id),StateName(name)
	{

	}
};

class Graph {
public:
	std::vector<Vertex> vertices;

};