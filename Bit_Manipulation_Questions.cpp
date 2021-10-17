#include <iostream>
using namespace std;

// Function to check whether a given number is power of 2 or not
int powerof2(int n)
{
    return (n && !(n & (n - 1)));
}

// Function to count the number of ones in a binary form of a number
int numberofones(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    cout << count << endl;
}

// Function to find all the possible subsets of a given set
void subsets(int a[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    // cout << powerof2(12) << endl;
    // numberofones(7);
    int arr[4] = {1, 2, 3, 4};
    subsets(arr, 4);
    return 0;
}