#include "Edge.h"

Edge::Edge()
{
	weight = 0;
}

Edge::Edge(int weight, Vertex start, Vertex end)
{
	this->weight = weight;
	this->start = start;
	this->end = end;
}

Edge::Edge(const Edge& other)
{
	this->weight = other.weight;
	this->start = other.start;
	this->end = other.end;
}

Edge::~Edge()
{
}

void Edge::setWeight(int weight)
{
	this->weight = weight;
}

void Edge::setStart(Vertex start)
{
	this->start = start;
}

void Edge::setEnd(Vertex end)
{
	this->end = end;
}

int Edge::getWeight() const
{
	return weight;
}

Vertex Edge::getStart() const
{
	return start;
}

Vertex Edge::getEnd() const
{
	return end;
}

bool Edge::operator==(const Edge& e) const
{
	if (weight != e.getWeight())
		return false;
	if (start != e.getStart())
		return false;
	if (end != e.getEnd())
		return false;
	return true;
}

void Edge::operator++()
{
	++weight;
}

void Edge::operator++(int)
{
	weight++;
}
