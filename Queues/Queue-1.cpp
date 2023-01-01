#include <bits/stdc++.h>
#define n 100
using namespace std;
class Queue
{
    int front;
    int rear;
    int *arr;

public:
    Queue();
    bool empty();
    bool full();
    void enqueue(int);
    void dequeue();
    int peek();
    void display();
};
void Queue::display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
Queue ::Queue()
{
    arr = new int[n];
    front = -1;
    rear = -1;
}
bool Queue::empty()
{
    if (front == -1 || front > rear)
    {
        return true;
    }
    return false;
}
bool Queue::full()
{
    if (rear == n - 1)
    {
        return true;
    }
    return false;
}
void Queue ::enqueue(int val)
{
    if (full())
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    rear++;
    arr[rear] = val;
    if (front == -1)
    {
        front++;
    }
}
void Queue::dequeue()
{
    if (empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    front++;
}
int Queue::peek()
{
    return arr[front];
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
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q.dequeue();
    cout << q.empty() << endl;
    return 0;
}