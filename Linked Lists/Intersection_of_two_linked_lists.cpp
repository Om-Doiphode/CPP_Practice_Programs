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
void InsertatHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}
void InsertatTail(Node *&head, int val)
{
    if (head == NULL)
    {
        InsertatHead(head, val);
        return;
    }
    else
    {
        Node *temp = new Node(val);
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
    }
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

int length(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
int intersect(Node *head1, Node *head2, int pos)
{
    pos--;
    Node *temp1 = head1;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersection(Node *&head1, Node *&head2)
{
    int d = 0;
    Node *p1, *p2;
    int l1 = length(head1);
    int l2 = length(head2);
    if (l1 > l2)
    {
        d = l1 - l2;
        p1 = head1;
        p2 = head2;
    }
    else
    {
        d = l2 - l1;
        p1 = head2;
        p2 = head1;
    }
    while (d)
    {
        if (p1 == NULL)
            return -1;
        p1 = p1->next;
        d--;
    }
    while (p2 != NULL)
    {
        if (p1 == p2)
        {
            return p1->data;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr1[]{9, 2, 3, 4, 56, 7, 8};
    int n1 = sizeof(arr1) / sizeof(int);
    int arr2[]{32, 39, 02, 10, 27};
    int n2 = sizeof(arr2) / sizeof(int);
    Node *head1 = new Node(1);
    Node *head2 = new Node(2);
    for (int i = 0; i < n1; i++)
    {
        InsertatTail(head1, arr1[i]);
    }

    display(head1);
    for (int i = 0; i < n2; i++)
    {
        InsertatTail(head2, arr2[i]);
    }
    display(head2);
    intersect(head1, head2, 3);
    cout << intersection(head1, head2) << endl;
    return 0;
}