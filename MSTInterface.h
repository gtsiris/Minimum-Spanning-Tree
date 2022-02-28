#include "MSTTypes.h"



void MSTKruskal(GraphType* graph);
GraphType *CreateGraph(int vertices, int edges);
int Find(SubsetType Subsets[], int i);
void Union(SubsetType Subsets[], int x, int y);
int CompareEdges(const void *FirstEdge, const void *SecondEdge);
void AddEdge(GraphType *, int, int, int, int);
