#include <iostream>
using namespace std;

// Worst Case Complexity : O(n^2)
// Best Case Complexity : O(n)
// Stable Algorithm
// Number of passes : n-1
// Not ADAPTIVE by default

void swap(int *a, int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Pass : " << i + 1 << endl;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void bubble_sort_adaptive(int *a, int n)
{
    int sorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Pass : " << i + 1 << endl;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                sorted = 1;
                swap(a[j], a[j + 1]);
            }
        }
    }
    if (sorted)
        return;
}
int main()
{
    int a[]{34, 56, 12, 10, 54};
    int n = 5;
    print(a, n);
    bubble_sort(a, n);
    print(a, n);
    return 0;
}