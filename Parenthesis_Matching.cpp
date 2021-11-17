#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool match(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
                return 0;
            else
                st.pop();
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
    string s = "1(*(9+8)(3*4)*2)";
    if (match(s))
        cout << "Balanced" << endl;
    else
        cout << "Unbalanced" << endl;
    return 0;
}