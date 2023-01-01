#include <bits/stdc++.h>
#include <stack>
using namespace std;
int matchchar(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}
bool match(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.empty())
                return 0;
            else
            {
                char poppedchar = st.top();
                st.pop();
                if (!matchchar(poppedchar, s[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (st.empty())
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "2+[]()(3*)()2()3";
    if (match(s))
        cout << "Balanced" << endl;
    else
        cout << "Unbalanced" << endl;
    return 0;
}