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

// Inserting an element in a linked list at different positions
void InsertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}
void InsertAtIndex(Node *&head, int val, int index)
{
    Node *temp = new Node(val);
    Node *p = head;
    Node *q = head->next;
    int count = 0;
    while (count != index - 1)
    {
        p = p->next;
        q = q->next;
        count++;
    }
    p->next = temp;
    temp->next = q;
}
void InsertAtEnd(Node *&head, int val)
{
    Node *temp = new Node(val);
    Node *n = head;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = temp;
    temp->next = NULL;
}
void InsertAfterNode(Node *&head, int val, Node *prevNode)
{
    Node *ptr = new Node(val);
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

// Deleting an element in a linked list from different positions
void DeleteFromFirst(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    delete todelete;
}
void DeleteFromIndex(Node *&head, int index)
{
    Node *p = head;
    Node *q = head->next;
    int count = 0;
    while (count != index - 1)
    {
        p = p->next;
        q = q->next;
        count++;
    }
    p->next = q->next;
    delete q;
}
void DeleteFromEnd(Node *&head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
}
bool ispresent(Node *&head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}
void DeleteVal(Node *&head, int val)
{
    Node *p = head;
    Node *q = head->next;
    if (ispresent(head, val))
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
// Reversing an entire Linked List
Node *reverse(Node *&head)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
// Reversing a linked list after k intervals
Node *reversek(Node *&head, int k)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;

        count++;
    }
    if (head != NULL)
        head->next = reversek(nextptr, k);
    return prevptr;
}
void MakeCycle(Node *&head, int index)
{
    Node *temp = head;
    Node *startNode;
    int count = 0;
    while (temp->next != NULL)
    {
        if (count == index)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = temp;
}
bool DetectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}
void RemoveCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
int main()
{
    cout << boolalpha;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    Node *seventh = new Node(7);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    display(head);
    InsertAfterNode(head, 19, second);
    display(head);
    Node *newhead = reversek(head, 2);
    display(newhead);
    MakeCycle(head, 3);
    cout << DetectCycle(head) << endl;
    RemoveCycle(head);
    cout << DetectCycle(head) << endl;
    return 0;
}