#include <iostream>
using namespace std;
bool sorted(int a[], int n)
{
    if (n == 1)
        return true;
    int restArray = sorted(a + 1, n - 1);
    return (a[0] < a[1] && restArray);
}
int firstocc(int a[], int n, int i, int key)
{
    if (i == n)
        return -1;
    if (a[i] == key)
        return i;
    return (firstocc(a, n, i + 1, key));
}
int lastocc(int a[], int n, int i, int key)
{
    if (i == n)
        return -1;
    int restArray = lastocc(a, n, i + 1, key);
    if (restArray != -1)
        return restArray;
    if (a[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[]{2, 2, 3, 2, 5};
    cout << lastocc(arr, 5, 0, 2);
    return 0;
}