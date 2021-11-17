#include <bits/stdc++.h>
using namespace std;
#define n 100
class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    bool isempty()
    {
        return (top == -1);
    }
    bool isfull()
    {
        return top == n;
    }
    void push(int val)
    {
        if (isfull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int val = arr[top];
        top--;
        cout << "Element " << val << " popped from the stack" << endl;
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
    int StackTop()
    {
        return arr[top];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << boolalpha;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.pop();
    cout << s.isempty() << endl;
    return 0;
}