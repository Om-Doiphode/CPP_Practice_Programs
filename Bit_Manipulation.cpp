#include <iostream>
using namespace std;
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int setBit(int n, int pos)
{
    return ((n | (1 << pos)));
}
int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (mask & n);
}
int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return ((n | (value << pos)));
}
int main()
{
    int n;
    cin >> n;

    // Getting Bit at postion 2
    cout << getBit(n, 2) << endl;

    // Setting Bit at position 3 to 1
    cout << setBit(n, 3) << endl;

    // Setting Bit at position 0 to 0
    cout << clearBit(n, 0) << endl;

    // Updating Bit at position 3 to 1
    cout << updateBit(n, 3, 1) << endl;
    return 0;
}