#include "Directed.h"

Directed::Directed()
{
	vertex = nullptr;
	edge = nullptr;
	number_of_vertices = 0;
	number_of_edges = 0;
}

Directed::Directed(int number_of_vertices, int number_of_edges)
{
	vertex = new Vertex[number_of_vertices]();
	edge = new Edge[number_of_edges];
	this->number_of_edges = number_of_edges;
	this->number_of_vertices = number_of_vertices;
}

Directed::~Directed()
{
	delete[] vertex;
	delete[] edge;
}

void Directed::setNumberOfVertices(int number_of_vertices)
{
	vertex = new Vertex[number_of_vertices]();
	this->number_of_vertices = number_of_vertices;
}

void Directed::setNumberOfEdges(int number_of_edges)
{
	edge = new Edge[number_of_edges];
	this->number_of_edges = number_of_edges;
}

bool Directed::addVertex(Vertex& v)
{
	for (int i = 0; i < number_of_vertices; i++) {
		if (vertex[i].getValue() == 0) {
			vertex[i] = v;
			return true;
		}
	}
	return false;
}

bool Directed::addVertices(Vertex* vArray)
{
	for (int i = 0; i < number_of_vertices; i++) {
		vertex[i] = vArray[i];
	}
	return true;
}

bool Directed::removeVertex(Vertex& v)
{
	Vertex temp;
	for (int i = 0; i < number_of_vertices; i++) {
		if (vertex[i] == v) {
			for (int j = i; j < number_of_vertices - 1; j++) {
				vertex[j] = vertex[j + 1];
			}
			vertex[number_of_vertices] = temp;
		//	number_of_vertices = number_of_vertices - 1;
			return true;
		}
	}
	return false;
}

bool Directed::addEdge(Edge& e)
{
	for (int i = 0; i < number_of_edges; i++) {
		if (edge[i].getWeight() == 0) {
			edge[i] = e;
			return true;
		}
	}
	return false;
}

bool Directed::addEdges(Edge* eArray)
{
	for (int i = 0; i < number_of_edges; i++) {
		edge[i] = eArray[i];
	}
	return true;
}

bool Directed::remove(Edge& e)
{
	Edge temp;
	for (int i = 0; i < number_of_edges; i++) {
		if (edge[i] == e) {
			for (int j = i; j < number_of_vertices - 1; j++) {
				edge[j] = edge[j + 1];
			}
			edge[number_of_edges] = temp;
			//number_of_edges = number_of_edges - 1;
			return true;
		}
	}
	return false;
}

bool Directed::searchVertex(const Vertex& v)
{
	for (int i = 0; i < number_of_vertices; i++) {
		if (vertex[i] == v) {
			return true;
		}
	}
	return false;
}

bool Directed::searchEdge(const Edge& e)
{
	for (int i = 0; i < number_of_edges; i++) {
		if (edge[i] == e) {
			return true;
		}
	}
	return false;
}

void Directed::display() const
{
	for (int i = 0; i < number_of_vertices; i++) {
		for (int m = 0; m < number_of_edges; m++) {
			if (vertex[i] == edge[m].getEnd()) {
				i++;
				m = -1;
			}
		}
		Vertex temp = vertex[i];
		for (int j = 0; j < number_of_edges; j++) {
			if (vertex[i] == edge[j].getStart()) {
				cout << vertex[i].getValue();
				temp = edge[j].getEnd();
				cout << " -(" << edge[j].getWeight() << ")-> " << edge[j].getEnd().getValue();
				for (int k = 0; k < number_of_edges; k++) {
					if (temp == edge[k].getStart()) {
							cout << " -(" << edge[k].getWeight() << ")-> " << edge[k].getEnd().getValue();
							temp = edge[k].getEnd();
					}
				}
				cout << endl;
			}
		}
	}
}

string Directed::toString() const
{
	string graph_representation;
	for (int i = 0; i < number_of_vertices; i++) {
		for (int m = 0; m < number_of_edges; m++) {
			if (vertex[i] == edge[m].getEnd()) {
				i++;
				m = -1;
			}
		}
		Vertex temp = vertex[i];
		for (int j = 0; j < number_of_edges; j++) {
			if (vertex[i] == edge[j].getStart()) {
				graph_representation = graph_representation + to_string(vertex[i].getValue());
				temp = edge[j].getEnd();
				graph_representation = graph_representation + "-";
				graph_representation = graph_representation + to_string(edge[j].getEnd().getValue());
				for (int k = 0; k < number_of_edges; k++) {
					if (temp == edge[k].getStart()) {
						graph_representation = graph_representation + "-";
						graph_representation = graph_representation + to_string(edge[k].getEnd().getValue());
						temp = edge[k].getEnd();
					}
				}
				graph_representation = graph_representation + "; ";
			}
		}
	}
	return graph_representation;
}

bool Directed::clean()
{
	Vertex temp;
	for (int i = 0; i < number_of_vertices; i++)
		vertex[i] = temp;
	Edge tempE;
	for (int i = 0; i < number_of_edges; i++)
		edge[i] = tempE;
	return true;
}

bool Directed::operator==(const Directed& g) const
{
	if (vertex != g.vertex)
		return false;
	if (edge != g.edge)
		return false;
	if (number_of_vertices != g.number_of_vertices)
		return false;
	if (number_of_edges != g.number_of_edges)
		return false;
	return true;
}

Directed& Directed::operator=(const Directed& g)
{
	if (this != &g) {
		delete[] vertex;
		number_of_vertices = g.number_of_vertices;
		vertex = new Vertex[number_of_vertices];
		delete[] edge;
		number_of_edges = g.number_of_edges;
		edge = new Edge[number_of_edges];
		for (int i = 0; i < number_of_vertices; i++)
			vertex[i] = g.vertex[i];
		for (int i = 0; i < number_of_edges; i++)
			edge[i] = g.edge[i];
	}
	return *this;
}

void Directed::operator++()
{
	for (int i = 0; i < number_of_edges; i++) {
		++edge[i];
	}
}

void Directed::operator++(int)
{
	for (int i = 0; i < number_of_edges; i++) {
		edge[i]++;
	}
}

Directed Directed::operator+(const Directed& g)
{
	Directed temp;
	temp.number_of_vertices = number_of_vertices + g.number_of_vertices;
	temp.number_of_edges = number_of_edges + g.number_of_edges;
	temp.vertex = new Vertex[temp.number_of_vertices];
	temp.edge = new Edge[temp.number_of_edges];
	for (int i = 0; i < number_of_vertices; i++)
		temp.vertex[i] = vertex[i];
	for (int i = number_of_vertices; i < temp.number_of_vertices; i++)
		temp.vertex[i] = g.vertex[i - number_of_vertices];
	for (int i = 0; i < number_of_edges; i++)
		temp.edge[i] = edge[i];
	for (int i = number_of_edges; i < temp.number_of_edges; i++)
		temp.edge[i] = g.edge[i - number_of_edges];
	return temp;
}

bool Directed::operator>(const Directed& g) const
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < number_of_edges; i++)
		sum1 = sum1 + edge[i].getWeight();
	for (int i = 0; i < g.number_of_edges; i++)
		sum2 = sum2 + g.edge[i].getWeight();
	if (sum1 > sum2)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& output, const Directed& graph)
{
	output << graph.toString();
	return output;
}
