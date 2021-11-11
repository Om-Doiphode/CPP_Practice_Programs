#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertatHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
void insertatTail(Node *&head, int val)
{
    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void evenafterodd(Node *&head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenstart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    if (even->next != NULL)
    {
        even->next = NULL;
    }
    odd->next = evenstart;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head = new Node(1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}