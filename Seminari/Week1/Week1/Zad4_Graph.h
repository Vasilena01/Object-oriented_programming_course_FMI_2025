#pragma once
#include <iostream>

struct Node
{
	char eticket[10];
};

struct Edge
{
	Node* v1;
	Node* v2;
};

struct Graph
{
	size_t nodesCount;
	size_t edgesCount;
	Edge* edges;
};

Graph* createGraph()
{
	size_t m;
	std::cin >> m;

	Graph* graph = new Graph();
	graph->edgesCount = 0;
	graph->nodesCount = m + 1;
	graph->edges = new Edge[m];
	return graph;
}

void strCopy(char* dest, const char* target)
{
	int i = 0;
	while (*target && i < 9)
	{
		dest[i] = *target;
		target++;
		i++;
	}
	dest[i] = '\0';
}

void addEdge(Graph* graph, const char* e1, char* e2)
{
	Node* v1 = new Node();
	strCopy(v1->eticket, e1);

	Node* v2 = new Node();
	strCopy(v2->eticket, e2);

	Edge* newEdges = new Edge[graph->edgesCount + 1];
	for (int i = 0; i < graph->edgesCount; i++)
	{
		newEdges[i] = graph->edges[i];
	}

	newEdges[graph->edgesCount] = { v1, v2 };
	delete[] graph->edges;
	graph->edges = newEdges;
	graph->edgesCount++;
}

int getVertexDegree(Graph* graph, const char* vertex)
{
	int degree = 0;

	for (size_t i = 0; i < graph->edgesCount; i++)
	{
		if (std::strcmp(graph->edges[i].v1->eticket, vertex) == 0 ||
			std::strcmp(graph->edges[i].v2->eticket, vertex) == 0)
		{
			degree++;
		}
	}

	return degree;
}

bool isCompleteGraph(Graph* graph)
{
    // Extract all unique vertex names
    char vertices[100][10];
    int vertexCount = 0;

    for (size_t i = 0; i < graph->edgesCount; i++)
    {
        bool foundV1 = false;
        for (int j = 0; j < vertexCount; j++)
        {
            if (std::strcmp(vertices[j], graph->edges[i].v1->eticket) == 0)
            {
                foundV1 = true;
                break;
            }
        }
        if (!foundV1)
        {
            strCopy(vertices[vertexCount], graph->edges[i].v1->eticket);
            vertexCount++;
        }

        bool foundV2 = false;
        for (int j = 0; j < vertexCount; j++)
        {
            if (std::strcmp(vertices[j], graph->edges[i].v2->eticket) == 0)
            {
                foundV2 = true;
                break;
            }
        }
        if (!foundV2)
        {
            strCopy(vertices[vertexCount], graph->edges[i].v2->eticket);
            vertexCount++;
        }
    }

    // In a complete graph, we must have exactly n(n-1)/2 edges
    int expectedEdges = (vertexCount * (vertexCount - 1)) / 2;
    if (graph->edgesCount != expectedEdges)
        return false;

    // Check if every vertex is connected to every other vertex
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            if (i == j) continue;

            bool foundEdge = false;
            for (size_t k = 0; k < graph->edgesCount; k++)
            {
                if ((std::strcmp(graph->edges[k].v1->eticket, vertices[i]) == 0 &&
                    std::strcmp(graph->edges[k].v2->eticket, vertices[j]) == 0) ||
                    (std::strcmp(graph->edges[k].v1->eticket, vertices[j]) == 0 &&
                        std::strcmp(graph->edges[k].v2->eticket, vertices[i]) == 0))
                {
                    foundEdge = true;
                    break;
                }
            }

            if (!foundEdge)
                return false;
        }
    }

    return true;
}

void deleteEdge(Graph*& graph, const Edge* edge)
{
	const char* e1 = edge->v1->eticket;
	const char* e2 = edge->v2->eticket;


	if (graph->edgesCount == 0)
		return;
	
	Edge* newEdges = new Edge[graph->edgesCount - 1];
	bool contains = false;
	int index = 0;
	size_t newSize = graph->edgesCount - 1;

	for (int i = 0; i < graph->edgesCount; i++)
	{
		if (std::strcmp(graph->edges[i].v1->eticket, e1) == 0 &&
			std::strcmp(graph->edges[i].v2->eticket, e2) == 0)
		{
			contains = true;
			delete[] graph->edges[i].v1;
			delete[] graph->edges[i].v2;
			continue;
		}

		if (index < newSize)
			newEdges[index++] = graph->edges[i];
	}

	if (!contains)
	{
		std::cout << "No such edge!" << std::endl;
		return;
	}

	delete[] graph->edges;
	graph->edges = newEdges;
	graph->edgesCount = newSize;
}

void input4()
{
	Graph* gr = createGraph();
	int m = gr->nodesCount - 1;
	for (int i = 0; i < m; i++)
	{
		char e1[10];
		char e2[10];
		std::cin >> e1 >> e2;
		addEdge(gr, e1, e2);
	}

	for (int i = 0; i < gr->edgesCount; i++)
		std::cout << gr->edges[i].v1->eticket << " " << gr->edges[i].v2->eticket << std::endl;

	std::cout << isCompleteGraph(gr);

	Edge* toDelete = new Edge();
	toDelete->v1 = new Node();
	strCopy(toDelete->v1->eticket, "vasi");

	toDelete->v2 = new Node();
	strCopy(toDelete->v2->eticket, "ivan");

	deleteEdge(gr, toDelete);

	for (int i = 0; i < gr->edgesCount; i++)
		std::cout << gr->edges[i].v1->eticket << " " << gr->edges[i].v2->eticket << std::endl;

	delete toDelete->v1;
	delete toDelete->v2;
	delete toDelete;

	for (size_t i = 0; i < gr->edgesCount; i++)
	{
		delete gr->edges[i].v1;
		delete gr->edges[i].v2;
	}
	delete[] gr->edges;
	delete gr;
}