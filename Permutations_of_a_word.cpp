#include <iostream>
using namespace std;
void permutation(string s, string ans = "")
{
    // Time Complexity : O(N*2^n)
    // Space Complexity : O(2^n)
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permutation(ros, ans + c);
    }
}
int main()
{
    permutation("ABC");
    return 0;
}