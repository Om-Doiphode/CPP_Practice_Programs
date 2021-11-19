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
class Queue
{
public:
    Node *front;
    Node *back;
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    bool empty();
    void enqueue(int);
    void dequeue();
    int peek();
};

bool Queue::empty()
{
    if (front == NULL)
        return true;
    return false;
}
void Queue::enqueue(int val)
{
    Node *n = new Node(val);
    if (front == NULL)
    {
        front = n;
        back = n;
        return;
    }
    back->next = n;
    back = n;
}
void Queue::dequeue()
{
    if (empty())
    {
        cout << "No elements in queue" << endl;
        return;
    }
    Node *todelete = front;
    front = front->next;
    delete todelete;
}
int Queue::peek()
{
    if (empty())
    {
        cout << "No elements in queue" << endl;
        return -1;
    }
    return front->data;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << boolalpha;
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.empty() << endl;
    return 0;
}