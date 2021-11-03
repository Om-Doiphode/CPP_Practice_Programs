#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void wave_sort(int *a, int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (a[i] > a[i - 1])
        {
            swap(a, i, i - 1);
        }
        if (a[i] > a[i + 1] && i <= 2)
        {
            swap(a, i, i + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]{34, 56, 12, 10, 54};
    int n = 5;
    wave_sort(a, n);
    print(a, n);
    return 0;
}