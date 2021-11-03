#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void dnf_sort(int *a,int n)
{
    int low=0;
    int high=n-1;
    int mid=0;
    while (mid<=high)
    {
        if (a[mid]==0)
        {
            swap(a,low,mid);
            low++;
            mid++;
        }
        else if (a[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(a,mid,high);
            high--;
        }
    }
    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]{0,1,2,0,0,2,1,1};
    int n=8;
    dnf_sort(a,n);
    print(a,n);
    return 0;
}