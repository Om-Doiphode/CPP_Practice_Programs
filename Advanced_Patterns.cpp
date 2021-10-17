#include <iostream>
using namespace std;


int factorial(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}
int comb(int n,int r)
{
    int ans=factorial(n)/(factorial(n-r)*factorial(r));
    return ans;
}
int main()
{
//  Diamond Shape Pattern
//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=2*i-1;++j)
        cout<<"*";
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=2*i-1;++j)
        cout<<"*";
        cout<<endl;
    }
//  Hollow Diamond Pattern
//     *
//    * *
//   *   *
//  *     *
// *       *
// *       *
//  *     *
//   *   *
//    * *
//     *
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=2*i-1;++j)
        {
            if(j==1 || j==2*i-1)
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
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=2*i-1;++j)
        {
            if(j==1 || j==2*i-1)
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
// Rhombus Pattern
//     *****
//    *****
//   *****
//  *****
// *****
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=n;j++)
        cout<<"*";
        cout<<endl;
    }
//  Hollow Rhombus Pattern
//     *****
//    *   *
//   *   *
//  *   *
// *****
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
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
// Number Pyramid Pattern
//     1
//    2 2
//   3 3 3
//  4 4 4 4
// 5 5 5 5 5
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
// Solid Butterfly Pattern
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// **********
// ****  ****
// ***    ***
// **      **
// *        *
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        for(int j=1;j<=(2*n-2*i);++j)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        for(int j=1;j<=(2*n-2*i);++j)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
    }
//  Hollow Butterfly Pattern
// *        *
// **      **
// * *    * *
// *  *  *  *
// *   **   *
// *   **   *
// *  *  *  *
// * *    * *
// **      **
// *        *
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1 || j==i)
            cout<<"*";
            else
            {
                cout<<" ";
            }
            
        }
        for(int j=1;j<=(2*n-2*i);++j)
        cout<<" ";
        for(int j=1;j<=i;j++)
        {
            if(j==1 || j==i)
            cout<<"*";
            else
            {
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1 || j==i)
            cout<<"*";
            else
            {
                cout<<" ";
            }
            
        }
        for(int j=1;j<=(2*n-2*i);++j)
        cout<<" ";
        for(int j=1;j<=i;j++)
        {
            if(j==1 || j==i)
            cout<<"*";
            else
            {
                cout<<" ";
            }
            
        }
        cout<<endl;
//     }
// Pascal's Traingle
//       1
//      1 1
//     1 2 1
//    1 3 3 1
//   1 4 6 4 1
//  1 5 10 10 5 1
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        cout<<" ";
        for(int j=0;j<=i;j++)
        {
            cout<<comb(i,j)<<" ";
        }
        cout<<endl;
    }
}