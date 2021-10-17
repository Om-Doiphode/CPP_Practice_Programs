#include <iostream>
using namespace std;


int main()
{
/* Rectangle Pattern
*****
*****
*****
*****
*****
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
*/
/*Hollow Rectangle
*****
*   *
*   *
*   *
*****
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1||i==n||j==1||j==n)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
*/
/*Half Pyramid Pattern
*
**
***
****
*****
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
*/
/* Inverted Pyramid Pattern
*****
****
***
**
*
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
*/
/* Pyramid Pattern after 180 degrees rotation
    *
   **
  ***
 ****
*****
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=n-i)
            cout<<" ";
            else
            cout<<"*";
        }
        cout<<endl;
    }
*/
/*Number Pyramid Pattern
1
12
123
1234
12345
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
*/
/* Inverted Number Pyramid Pattern
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
*/
/* Number Pattern -2
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
*/
/* Floyd's Triangle
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
    int n;
    int count=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
*/
/* 0-1 Pattern
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((i+j)%2==0)
            {
                cout<<"1"<<" ";
            }
            else
            {
                cout<<"0"<<" ";
            }
            
        }
        cout<<endl;
    }
*/
}
