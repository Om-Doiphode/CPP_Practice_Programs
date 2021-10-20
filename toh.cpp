#include <iostream>
using namespace std;
void towerofhanoi(int n, char src, char dest, char helper)
{
    // Time Complexity : O(2^n)
    // Space Complexity : O(1)
    if (n == 0)
        return;
    towerofhanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerofhanoi(n - 1, helper, dest, src);
}
int main()
{
    towerofhanoi(3, 'A', 'C', 'B');
    return 0;
}