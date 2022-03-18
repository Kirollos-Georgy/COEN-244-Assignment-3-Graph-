#pragma once
#include "Graph.h"
#include <string>

class Directed : public Graph
{
	friend ostream& operator<<(ostream& output, const Directed& graph);

private:
	Vertex* vertex;
	Edge* edge;
	int number_of_vertices;
	int number_of_edges;

public:
	Directed();
	Directed(int number_of_vertices, int number_of_edges);
	~Directed();
	void setNumberOfVertices(int number_of_vertices);
	void setNumberOfEdges(int number_of_edges);
	bool addVertex(Vertex& v);
	bool addVertices(Vertex* vArray);
	bool removeVertex(Vertex& v);
	bool addEdge(Edge& e);
	bool addEdges(Edge* eArray);
	bool remove(Edge& e);
	bool searchVertex(const Vertex& v);
	bool searchEdge(const Edge& e);
	void display() const;
	string toString() const;
	bool clean();
	bool operator==(const Directed& g) const;
	Directed& operator=(const Directed& g);
	void operator++();
	void operator++(int);
	Directed operator+(const Directed& g1);
	bool operator>(const Directed& g) const;
};

