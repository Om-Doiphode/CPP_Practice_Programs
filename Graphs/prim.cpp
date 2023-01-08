// MST from Prim's algorithm
#include <iostream>
#define INF 32767
#define V 7
using namespace std;
void Prim(Graph g)
{
    int n = g.vertices.size();
    int **G = new int *[n];

    for (int i = 0; i < n; i++)
    {
        G[i] = new int[n];
    }
    for (int i = 0; i < g.vertices.size(); i++)
    {
        for (int j = 0; j < n; j++)
            G[i][j] = INF;
    }
    for (int i = 0; i < g.vertices.size(); i++)
    {
        Node *p = g.vertices[i];
        while (p != NULL)
        {
            G[i][p->data] = p->cost;
            p = p->next;
        }
    }
    int u, v, min = INF;
    int near[V]{INF};
    int t[2][V - 2]{0};
    for (int i = 1; i < V; i++)
    {
        near[i] = INF;
        for (int j = i; j < V; j++)
        {
            if (G[i][j] < min)
            {
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for (int i = 1; i < V; i++)
    {
        if (near[i] != 0)
        {
            if (G[i][u] < G[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        min = INF;
        int k;
        for (int j = 1; j < V; j++)
        {
            if (near[j] != 0 && G[j][near[j]] < min)
            {
                k = j;
                min = G[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (int j = 1; j < V; j++)
        {
            if (near[j] != 0 && G[j][k] < G[j][near[j]])
                near[j] = k;
        }
    }
    int sum = 0;
    for (int i = 0; i < V - 2; i++)
    {
        int c = G[t[0][i]][t[1][i]];
        cout << "[" << t[0][i] << "]---[" << t[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST : " << sum << endl;
}
