#include "graph.h"
#define I 32767 // Infinity
#define V 7     // # of vertices in Graph
#define E 9     // # of edges in Graph
void PrintMCST(int T[][V - 1], int A[][E]);
void Union(int u, int v, int s[]);
int Find(int u, int s[]);
void KruskalsMCST(Graph g);