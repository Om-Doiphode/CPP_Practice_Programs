#include <iostream>
using namespace std;

// Worst Case Complexity: O(n^2) -> When the array is already sorted
// Best Case Complexity : O(nlogn) -> When the pivot is at the center
// Average Case Complexity : O(nlogn)
// Inplace Algorithm
// STABLE : No
// Recursive Algorithm

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
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);
    swap(a[low], a[j]);
    return j;
}
int quick_sort(int *a, int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high); //index of pivot after partition
        quick_sort(a, low, partitionindex - 1);   //sort left array
        quick_sort(a, partitionindex + 1, high);  //sort right array
    }
}
int main()
{
    int a[]{38, 20, 01, 99, 18, 24};
    int n = 6;
    print(a, n);
    quick_sort(a, 0, n - 1);
    print(a, n);
    return 0;
}