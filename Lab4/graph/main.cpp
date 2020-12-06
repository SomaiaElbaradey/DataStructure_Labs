#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph graph;

    Vertex *A, *B, *C, *D, *E, *F, *G, *H;
    A = new Vertex('0');
    B = new Vertex('1');
    C = new Vertex('2');
    D = new Vertex('3');
    E = new Vertex('4');
    F = new Vertex('5');
    G = new Vertex('6');
    H = new Vertex('7');
////////////////////////////////////////////
    graph.AddVertex(A);
    graph.AddVertex(B);
    graph.AddVertex(C);
    graph.AddVertex(D);
    graph.AddVertex(E);
    graph.AddVertex(F);
    graph.AddVertex(G);
    graph.AddVertex(H);

////////////////////////////////////////////
    graph.AssignEdge(A, B, 6);
    graph.AssignEdge(A, C, 1);
    graph.AssignEdge(A, E, 8);
    graph.AssignEdge(C, F, 6);
    graph.AssignEdge(C, G, 4);
    graph.AssignEdge(D, H, 2);
    graph.AssignEdge(E, G, 4);
    graph.AssignEdge(E, H, 5);
    graph.AssignEdge(F, G, 1);
    graph.AssignEdge(F, H, 5);

////////////////////////////////////////////
    //graph.DepthFirst(A, A);
    graph.Dijkstra(F);
    graph.Traverse();
    return 0;
}
