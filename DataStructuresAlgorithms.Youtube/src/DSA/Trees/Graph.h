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
	Vertex() = default;
	Vertex(int id, const std::string& name) :
	StateID(id),StateName(name)
	{

	}
};

class Graph {
public:
	std::vector<Vertex> vertices;
	void AddVertex(const Vertex& object) {
		bool check =CheckVertexExist(object.StateID);
	}
	Vertex& GetVertex(int id){
		for (auto& vertex : vertices) {
			if (vertex.StateID == id)
				return vertex;
		}
	}
	void AddEdge(int fromVertex, int toVertex, int weight) {
		bool check1 = CheckVertexExist(fromVertex);
		bool check2 = CheckVertexExist(toVertex);
		if ((check1 && check2) == true) {
			bool check3 = CheckEdgeExist(fromVertex, toVertex);
			if (check3) {
				std::cout << "Edge already exist " << std::endl;
			}
			else {
				for (auto& vertex : vertices) {
					if (vertex.StateID == fromVertex) {
						Edge e(toVertex, weight);
						vertex.EdgeList.emplace_back(e);
					}
					else if(vertex.StateID == toVertex) {
						Edge e(fromVertex, weight);
						vertices.emplace_back(e);
					}
				}
			}
		}
	}

	bool CheckEdgeExist(int fromVertex, int toVertex) {
		Vertex v = GetVertex(fromVertex);
		const std::list<Edge>& e = v.EdgeList;
		for (auto& it : e) {
			if (it.DestinationVertexID == toVertex)
				return true;
		}
		return false;
	}
	bool CheckVertexExist(int ID) {
		for (const Vertex& vertex : vertices) {
			if (vertex.StateID == ID)
				return true;
		}
		return false;
	}
	static void Maine() {
		Graph g;
		std::string sname;
		int id1, id2, w;
		int option;
		bool check;

		do {
			std::cout << "What operation do you want to perform? " <<
				" Select Option number. Enter 0 to exit." << std::endl;
			std::cout << "1. Add Vertex" << std::endl;
			std::cout << "2. Update Vertex" << std::endl;
			std::cout << "3. Delete Vertex" << std::endl;
			std::cout << "4. Add Edge" << std::endl;
			std::cout << "5. Update Edge" << std::endl;
			std::cout << "6. Delete Edge" << std::endl;
			std::cout << "7. Check if 2 Vertices are Neigbors" << std::endl;
			std::cout << "8. Print All Neigbors of a Vertex" << std::endl;
			std::cout << "9. Print Graph" << std::endl;
			std::cout << "10. Clear Screen" << std::endl;
			std::cout << "0. Exit Program" << std::endl;
			std::cin >> option;
			Vertex v1;

			switch (option) {
			case 0:

				break;

			case 1:
				std::cout << "Add Vertex Operation -" << std::endl;
				std::cout << "Enter State ID :";
				std::cin >> id1;
				std::cout << "Enter State Name :";
				std::cin >> sname;
				v1 = Vertex(id1, sname);
				g.AddVertex(v1);

				break;
			}
		}
	}
};