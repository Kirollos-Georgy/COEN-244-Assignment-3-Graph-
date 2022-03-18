#pragma once
#include "Vertex.h"

class Edge
{
private:
	int weight;
	Vertex start;
	Vertex end;

public:
	Edge();
	Edge(int weight, Vertex start, Vertex end);
	Edge(const Edge& other);
	~Edge();
	void setWeight(int weight);
	void setStart(Vertex start);
	void setEnd(Vertex end);
	int getWeight() const;
	Vertex getStart() const;
	Vertex getEnd() const;
	bool operator==(const Edge& e) const;
	void operator++();
	void operator++(int);
};