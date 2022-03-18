#pragma once
#include <iostream>
#include "Edge.h"

using namespace std;

class Graph
{
public:
	Graph(){};
	virtual ~Graph() {};
	virtual void setNumberOfVertices(int number_of_vertices) = 0;
	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addVertices(Vertex* vArray) = 0;
	virtual bool removeVertex(Vertex& v) = 0;
	virtual bool addEdge(Edge& e) = 0;
	virtual bool addEdges(Edge* eArray) = 0;
	virtual bool remove(Edge& e) = 0;
	virtual bool searchVertex(const Vertex& v) = 0;
	virtual bool searchEdge(const Edge& e) = 0;
	virtual void display() const = 0;
	virtual string toString() const = 0;
	virtual bool clean() = 0;
};

