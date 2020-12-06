#ifndef VERTEX_H
#define VERTEX_H
#include "LinkedList.h"
typedef class Vertex Vertex;

class Edge
{
public:
    int Weight;
    Vertex *Adjacent;

    Edge(Vertex *adj, int weight)
    {
        Adjacent = adj;
        Weight = weight;
    }
};

class Vertex
{
    public:
        char Key, Path;
        int Visited, Cost;
        LinkedList<Edge> Edges;
        Vertex(char key)
        {
            Key = key;
            Visited = 0;
            Cost = 0;
        }

        void AddEdge(Vertex *adjacent, int weight)
        {
            Edges.Add(new Edge(adjacent, weight));
        }
};

#endif // VERTEX_H
