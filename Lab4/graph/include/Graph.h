#ifndef GRAPH_H
#define GRAPH_H
#include <string.h>

#include "LinkedList.h"
#include "Vertex.h"

using namespace std;

class Graph
{
    LinkedList<Vertex> vertices;

public:
    void AddVertex(Vertex *vertex)
    {
        vertices.Add(vertex);
    }

    void AssignEdge(Vertex *src, Vertex *dst, int weight)
    {
        src->AddEdge(dst, weight);
        dst->AddEdge(src, weight);
    }

    void DepthFirst(Vertex *startVertex, Vertex *fromVertex)
    {
        if(startVertex->Visited == 1)
            return;

        cout << "Visiting " << startVertex->Key << "\t from " << fromVertex->Key << endl;
        startVertex->Visited = 1;

        Edge* edge = startVertex->Edges.BeginIteration();

        while(edge != NULL)
        {
            DepthFirst(edge->Adjacent, startVertex);
            edge = startVertex->Edges.GetNext();
        }
    }

    void Dijkstra(Vertex *startVertex)
    {
        InitializeForDijkstra();

        startVertex->Cost = 0;

        Vertex *min = startVertex;
        while(min != NULL)
        {
            min->Visited = 1;
            CalculateCost(min);
            min = GetMinCost();
        }
    }
    void Traverse()
    {
        Vertex *vertex = vertices.BeginIteration();
        Vertex *ptr;
        int flag1 = -1, flag2;
        while(vertex != NULL)
        {
            ptr = vertex;
            cout<< "Path: " << ptr->Key << "   is \t";

            while(ptr->Path != '\0')
            {
                cout << ptr->Key << "  ";
                ptr = Search(ptr->Path);
            }

            flag1++;
            flag2 = 0;
            cout << ptr->Key << endl;
            vertices.BeginIteration();

            while(flag2 < flag1)
            {
                vertices.GetNext();
                flag2++;
            }
            vertex = vertices.GetNext();
        }
    }
private:
    void InitializeForDijkstra()
    {
        Vertex *vertex = vertices.BeginIteration();

        while(vertex != NULL)
        {
            vertex->Visited = 0;
            vertex->Cost = 10000;
            vertex->Path = '\0';
            vertex = vertices.GetNext();
        }
    }
    Vertex* Search(char path)
    {
        Vertex *vertex = vertices.BeginIteration();
        while(vertex != NULL)
        {
            if(vertex->Key == path)
                return vertex;
            vertex = vertices.GetNext();
        }
    }
    void CalculateCost(Vertex *vertex)
    {
        Edge *edge = vertex->Edges.BeginIteration();

        while(edge != NULL)
        {
            if(edge->Adjacent->Cost > (vertex->Cost + edge->Weight))
            {
                edge->Adjacent->Cost = vertex->Cost + edge->Weight;
                edge->Adjacent->Path = vertex->Key;
            }

            edge = vertex->Edges.GetNext();
        }
    }

    Vertex* GetMinCost()
    {
        int found = 0;
        Vertex *vertex = vertices.BeginIteration(), *min = NULL;

        while(vertex != NULL)
        {
            if(vertex->Visited == 0)
            {
                if(min == NULL || (min->Cost > vertex->Cost))
                    min = vertex;

                found = 1;
            }
            vertex = vertices.GetNext();
        }
        if(found)
            return min;
        return NULL;
    }
};

#endif // GRAPH_H
