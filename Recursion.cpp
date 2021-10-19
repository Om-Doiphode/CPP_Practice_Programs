#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}
int power(int n, int p)
{
    if (p == 0)
        return 1;
    return n * power(n, p - 1);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void dec(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    cout << n << endl;
    dec(n - 1);
}
void inc(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    inc(n - 1);
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;
    // cout << sum(n) << endl;
    // cout << power(n, 3) << endl;
    // cout << factorial(n) << endl;
    // cout << fib(n) << endl;
    // inc(n);
    return 0;
}