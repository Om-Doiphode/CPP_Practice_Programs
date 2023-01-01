#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;
int postfixeval(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.top();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(op1 ^ op2);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "46+2/5*7+";
    cout << postfixeval(s) << endl;
    return 0;
}