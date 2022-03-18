#include "Vertex.h"

int Vertex::count = 1;

Vertex::Vertex()
{
	value = 0;
	ID = 0;
}

Vertex::Vertex(int value)
{
	this->value = value;
	ID = count;
	count++;
}

Vertex::Vertex(const Vertex& other)
{
	this->value = other.value;
	this->ID = other.ID;
}

Vertex::~Vertex()
{
}

void Vertex::setValue(int value)
{
	this->value = value;
}

void Vertex::setID(int ID)
{
	this->ID = ID;
}

int Vertex::getValue() const
{
	return value;
}

int Vertex::getID() const
{
	return ID;
}

void Vertex::print()
{
	cout << "ID: " << ID << " Value: " << value;
}

const Vertex& Vertex::operator=(const Vertex& v)
{
	value = v.value;
	ID = v.ID;
	return *this;
}

bool Vertex::operator==(const Vertex& v) const
{
	if (value != v.getValue())
		return false;
	if (ID != v.getID())
		return false;
	return true;
}

bool Vertex::operator!=(const Vertex& v) const
{
	return !(*this == v);
}