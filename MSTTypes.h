typedef struct EdgeTag {
  int FirstVertex;
  int SecondVertex;
  int Weight;
} EdgeType;
 
typedef struct GraphTag {
  int Vertices;
  int Edges;
  EdgeType* Edge;
} GraphType;
 
typedef struct SubsetTag {
  int Parent;
  int Rank;
}SubsetType;
