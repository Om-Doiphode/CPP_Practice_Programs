#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (b)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}