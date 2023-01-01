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
Node *kappend(Node *&head, int k)
{
    Node *newHead;
    Node *newTail;
    Node *tail = head;
    int count = 1;
    int l = length(head);
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head, *second, *third, *fourth, *fifth, *sixth;
    head = new Node(1);
    second = new Node(2);
    third = new Node(3);
    fourth = new Node(4);
    fifth = new Node(5);
    sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    display(head);
    cout << length(head) << endl;

    Node *newlist = kappend(head, 3);
    display(newlist);
    return 0;
}