#include <iostream>
using namespace std;
// Program for counting possible number of paths
int countPaths(int s, int e)
{
    // Time Complexity : O(2^n)
    // Space Complexity : O(2^n)
    if (s == e)
        return 1;
    if (s > e)
        return 0;
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPaths(s + i, e);
    }
    return count;
}

// Program for counting possible numbebr of paths in a 2D board
int countPathsMaze(int n, int i, int j)
{
    // Time Complexity : O(2^n)
    // Space Complexity : O(2^n)
    if (i == n - 1 && j == n - 1)
        return 1;
    if (i >= n || j >= n)
        return 0;

    return countPathsMaze(n, i + 1, j) + countPathsMaze(n, i, j + 1);
}
int main()
{
    cout << countPaths(0, 3) << endl;
    cout << countPathsMaze(3, 0, 0) << endl;
    return 0;
}