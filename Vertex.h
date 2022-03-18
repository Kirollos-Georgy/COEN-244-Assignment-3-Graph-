#pragma once
#include <iostream>

using namespace std;

class Vertex
{
private:
	int value;
	int ID;
	static int count;

public:
	Vertex();
	Vertex(int value);
	Vertex(const Vertex& other);
	~Vertex();
	void setValue(int value);
	void setID(int ID);
	int getValue() const;
	int getID() const;
	void print();
	const Vertex& operator=(const Vertex& v);
	bool operator==(const Vertex& v) const;
	bool operator!=(const Vertex& v) const;
};