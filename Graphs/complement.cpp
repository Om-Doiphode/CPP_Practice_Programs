#include "complement.h"
Graph addEdgesComplement(Graph g, int val)
{
    Node *head = NULL;
    insertAtTail(head, val);
    g.vertices.push_back(head);
    int n = nonConnectedNodes.size();
    for (int i = 0; i < n; i++)
    {
        insertAtTail(head, nonConnectedNodes[i], 1);
    }
    return g;
}
Graph complement(Graph g)
{
    Graph new_graph;
    Node *head = NULL;
    int n = g.vertices.size();
    for (int i = 0; i < g.vertices.size(); i++)
    {
        int *dist_arr = new int[n];
        // dist_arr[0] = -1;
        for (int i = 0; i < n; i++)
        {
            dist_arr[i] = 0;
        }
        Node *p = g.vertices[i];
        while (p != NULL)
        {
            dist_arr[p->data]++;
            p = p->next;
        }
        for (int j = 0; j < n; j++)
        {
            if (dist_arr[j] == 0)
            {
                nonConnectedNodes.push_back(j);
            }
        }
        new_graph = addEdgesComplement(new_graph, i);
        nonConnectedNodes.clear();
    }
    return new_graph;
}