#include <iostream>
using namespace std;

// Worst Case Complexity: O(n^2)
// ADAPTIVE : No
// STABLE : No
// Number of passes : n-1
// Number of comaprisons : n(n-1)/2
// Advantage : Performs minimum number of swaps

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void swap(int *a, int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}
int selection_sort(int *a, int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
int main()
{
    int a[]{38, 20, 01, 99, 18, 24};
    int n = 6;
    print(a, n);
    selection_sort(a, n - 1);
    print(a, n);
    return 0;
}