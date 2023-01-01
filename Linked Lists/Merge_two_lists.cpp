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
int swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void sort(Node *&head)
{
    Node *temp = head;
    int l = length(head);
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
        {
            swap(temp->data, temp->next->data);
        }
        temp = temp->next;
    }
}

Node *merge(Node *&head1, Node *&head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *dummy = new Node(-1);
    Node *ptr3 = dummy;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return (dummy->next);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *head1 = new Node(1);
    InsertatTail(head1, 23);
    InsertatTail(head1, 3);
    InsertatTail(head1, 4);
    display(head1);

    sort(head1);

    Node *head2 = new Node(17);
    InsertatTail(head2, 89);
    InsertatTail(head2, 34);
    InsertatTail(head2, 45);
    display(head2);

    sort(head2);

    Node *newlist = merge(head1, head2);
    display(newlist);
    return 0;
}