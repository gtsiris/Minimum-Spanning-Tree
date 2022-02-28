#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MSTInterface.h"


void MSTKruskal(GraphType* graph) {  /* Construct MST using Kruskal's algorithm */
  int vertices = graph->Vertices;
  int MSTedges = 0;  /* Index */
  int sorted_edges = 0;  /* Index */
  int v;  /* Index */
  int x, y;
  EdgeType MST[vertices];
  
  qsort(graph->Edge, graph->Edges, sizeof(graph->Edge[0]), CompareEdges);  /* Sort all the edges in increasing order of weights */
  SubsetType *Subsets = malloc( vertices * sizeof(SubsetType) );  /* Allocate memory for subsets */
  for (v = 0; v < vertices; v++) {  /* Construct subsets with single elements*/
      Subsets[v].Parent = v;
      Subsets[v].Rank = 0;
  }
  while (MSTedges < vertices - 1) {  /* Number of edges in MST is at most vertices-1 */
    EdgeType next_edge = graph->Edge[sorted_edges++];  /* Start from the edge with the smallest weight and then increase index */
    x = Find(Subsets, next_edge.FirstVertex);
    y = Find(Subsets, next_edge.SecondVertex);
    if (x != y) {  /* Add this edge only if it does not cause cycle in MST */
        MST[MSTedges++] = next_edge;
        Union(Subsets, x, y);
    }
  }
  printf("The MST has the following edges:\n");  /* Print the edges of MST */
  for (sorted_edges = 0; sorted_edges < MSTedges; ++sorted_edges)
      printf("{%d,%d} -> weight: %d\n", MST[sorted_edges].FirstVertex, MST[sorted_edges].SecondVertex, MST[sorted_edges].Weight);
  return;
}

int CompareEdges(const void *FirstEdge, const void *SecondEdge) {  /* Argument in qsort */
  EdgeType *EdgeA = (EdgeType *)FirstEdge;
  EdgeType *EdgeB = (EdgeType *)SecondEdge;
  return (EdgeA->Weight > EdgeB->Weight);  /* Compare two edges according to their weights */
}

int Find(SubsetType Subsets[], int i) {  /* Find set of an element i */
  if (Subsets[i].Parent != i)  /* Find root and make it parent of i */
      Subsets[i].Parent = Find(Subsets, Subsets[i].Parent);
  return Subsets[i].Parent;
}
 
void Union(SubsetType Subsets[], int x, int y) {  /* Union by rank of two sets which include x and y */
  int xroot = Find(Subsets, x);
  int yroot = Find(Subsets, y);
  if (Subsets[xroot].Rank < Subsets[yroot].Rank)  /* Attach smaller rank tree under root of high */
      Subsets[xroot].Parent = yroot;
  else if (Subsets[xroot].Rank > Subsets[yroot].Rank)
      Subsets[yroot].Parent = xroot;
  else {  /* In case of same ranks then make one of them root and increase its rank */
      Subsets[yroot].Parent = xroot;
      Subsets[xroot].Rank++;
  }
}

GraphType *CreateGraph(int vertices, int edges) {  /* Create a graph */
  GraphType* graph = malloc(sizeof(GraphType));
  graph->Vertices = vertices;
  graph->Edges = edges;
  graph->Edge = malloc(graph->Edges * sizeof(EdgeType));
  return graph;
}

void AddEdge(GraphType *graph, int pos, int vertex1, int vertex2, int weight) { /* Add an edge to the graph */
  graph->Edge[pos].FirstVertex = vertex1;
  graph->Edge[pos].SecondVertex = vertex2;
  graph->Edge[pos].Weight = weight;
}
