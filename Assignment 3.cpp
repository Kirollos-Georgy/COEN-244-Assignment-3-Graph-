#include <iostream> 
#include "Graph.h"
#include "Directed.h"

int main()
{
    Vertex first(1);
    Vertex second(2);
    Vertex third(3);
    Vertex fourth(4);
    Vertex fifth(5);
    Vertex sixth(6);
    Vertex seventh(7);
    Vertex eigths(8);
    Vertex ninth(9);
    Vertex tenth(10);
    Vertex arr1[5] = {sixth, seventh, eigths, ninth, tenth };
    Edge one(1, first, second);
    Edge two(2, second, fourth);
    Edge three(5, fourth, fifth);
    Edge four(3, first, third);
    Edge five(6, third, fifth);
    Edge six(1, sixth, tenth);
    Edge seven(2, sixth, seventh);
    Edge eight(2, seventh, eigths);
    Edge nine(2, eigths, ninth);
    Edge ten(2, fifth, sixth);
    Edge arrE1[4] = { six, seven, eight, nine };
    Directed g1(5, 5);
    Directed g2(5, 4);
    g1.addVertex(first);
    g1.addVertex(second);
    g1.addVertex(third);
    g1.addVertex(fourth);
    g1.addVertex(fifth);
    g1.addEdge(one);
    g1.addEdge(two);
    g1.addEdge(three);
    g1.addEdge(four);
    g1.addEdge(five);
    g2.addVertices(arr1);
    g2.addEdges(arrE1);
  //  grap.remove(five);
    cout << "Display of the first graph (The output format is vertex -(weight)-> vertex):" << endl;
    g1.display();
    cout << endl;
    cout << "Display of the second graph (The output format is vertex -(weight)-> vertex):" << endl;
    g2.display();
    cout << endl;
    cout << "Checking if the first graph is equal to the second graph: ";
    if (g2 == g1) {
        cout << "The two graph are equal" << endl;
    }
    else
        cout << "The two graph are not equal" << endl;
    cout << endl;
    cout << "Cheking if the first graph is bigger than the second graph: ";
    if (g1 > g2) {
        cout << "Graph one is bigger than graph 2" << endl;
    }
    else
        cout << "Graph one is not bigger than graph 2" << endl;
    Directed g3 = g1 + g2;
    cout << endl;
    cout << "Dispalying the third graph after assigning it the sum of the first graph and the second graph, using the output operator that access the toString function" << endl;
    cout << g3;
    g2 = g1;
    cout << endl;
    cout << endl;
    cout << "Displaying the second graph after assigning it the first graph:" << endl;
    cout << g2;
}