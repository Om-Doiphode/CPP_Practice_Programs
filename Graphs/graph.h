#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#define max 5
#define INFINITY 9999
using namespace std;
vector<int> nonConnectedNodes;
class Node
{
public:
    int data;
    int cost;
    Node *next;
    Node(int val, int c)
    {
        data = val;
        cost = c;
        next = NULL;
    }
};
class Graph
{
public:
    vector<Node *> vertices;
};
void create(Node *&, int, int);
void insertAtHead(Node *&head, int val, int c = 0);
void insertAtTail(Node *&head, int val, int c = 0);
void display(Node *head);
Graph addEdges(Graph g, int val);
void displayGraph(Graph g);
bool findVertex(Node *head, int vert);
void deleteNode(Node *&head, int val);
#endif