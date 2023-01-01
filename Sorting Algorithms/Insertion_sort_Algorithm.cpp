#include <iostream>
using namespace std;

// Worst Case Compexity : O(n^2)
// Best Case Complexity : O(n)
// STABLE Algorithm
// ADAPTIVE Algorithm
// Number of passes : n-1
// Number of comparisons : n(n-1)/2

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int insertion_sort(int *a, int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[]{38, 20, 01, 99, 18, 24};
    int n = 6;
    print(a, n);
    insertion_sort(a, n);
    print(a, n);
    return 0;
}