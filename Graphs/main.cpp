#include "graph.cpp"
#include "complement.cpp"
#include "prim.cpp"
#include "kst.cpp"
int main()
{
    Graph g;
    g = addEdges(g, 0);
    g = addEdges(g, 1);
    g = addEdges(g, 2);
    g = addEdges(g, 3);
    g = addEdges(g, 4);
    // g = addEdges(g, 5);
    // g = addEdges(g, 6);
    // g = addEdges(g, 7);
    displayGraph(g);
    Graph comp = complement(g);
    displayGraph(comp);
    // KruskalsMCST(g);
    // Prim(g);
}
