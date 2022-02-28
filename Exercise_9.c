#include "MSTInterface.h"



int main(void) {
  /* Example of a weighted graph for testing:
          3   
      0-------1
      | \     |
    8 |  6\   | 7
      |     \ |
      3-------2
          4                                */
         
  int Vertices = 4;  /* Number of vertices */
  int Edges = 5;  /* Number of edges */
  int i = 0;
  
  GraphType *Graph = CreateGraph(Vertices, Edges);
  
  AddEdge(Graph, i++, 0, 1, 3);
  AddEdge(Graph, i++, 0, 2, 6);
  AddEdge(Graph, i++, 0, 3, 8);
  AddEdge(Graph, i++, 1, 2, 7);
  AddEdge(Graph, i++, 2, 3, 4);
  

  MSTKruskal(Graph);

  return 0;
}
