#include "graph.h"
void create(Node *&head, int val, int c)
{
    head->data = val;
    head->cost = c;
    head->next = NULL;
}
void insertAtHead(Node *&head, int val, int c)
{
    Node *temp = new Node(val, c);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&head, int val, int c)
{
    if (head == NULL)
    {
        insertAtHead(head, val, c);
        return;
    }
    Node *temp = new Node(val, c);
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}
void display(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
Graph addEdges(Graph g, int val)
{
    Node *head = NULL;
    insertAtTail(head, val);
    g.vertices.push_back(head);
    cout << "Enter the number of vertices which are directly connected to " << head->data << endl;
    int n;
    cin >> n;
    while (n--)
    {
        int vert, cost;
        cout << "Enter the vertex: ";
        cin >> vert;
        cout << "Enter the cost: ";
        cin >> cost;
        insertAtTail(head, vert, cost);
    }

    return g;
}
void displayGraph(Graph g)
{
    cout << "Src \t\t\t"
         << "Dest\t\t\t"
         << "Cost" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < g.vertices.size(); i++)
    {
        Node *p = g.vertices[i];
        cout << p->data;
        while (p != NULL)
        {
            cout << "\t\t\t" << p->data << "\t\t\t";
            cout << p->cost << endl;
            p = p->next;
        }
        cout << endl;
    }
}
bool findVertex(Node *head, int vert)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == vert)
            return true;
        p = p->next;
    }
    return false;
}
void deleteNode(Node *&head, int val)
{
    Node *p = head;
    Node *q = head->next;
    if (findVertex(head, val))
    {
        while (q->data != val)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        delete q;
    }
}