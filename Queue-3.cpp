#include <bits/stdc++.h>
#include <stack>
using namespace std;
class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    bool empty(void);
    void enqueue(int val);
    int dequeue(void);
    void display(void);
};
bool Queue::empty()
{
    if (s1.empty() && s2.empty())
    {
        return true;
    }
    return false;
}
void Queue::enqueue(int val)
{
    s1.push(val);
}
int Queue::dequeue()
{
    if (empty())
    {
        cout << "No elements in queue" << endl;
        return -1;
    }
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int val = s2.top();
    s2.pop();
    return val;
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
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.empty() << endl;
    return 0;
}