#include <iostream>
using namespace std;
void reverse(string s)
{
    // Time Complexity : O(n^2)
    // Space Complexity : O(n^2)
    if (s.length() == 0)
        return;
    reverse(s.substr(1));
    cout << s[0];
}
void replacePi(string s)
{
    // Time Complexity : O(n^2)
    // Space Complexity : O(n^2)
    if (s.length() == 0)
        return;
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

string removeDup(string s)
{
    // Time Complexity : O(n^2)
    // Space Complexity : O(n^2)
    if (s.length() == 0)
        return "";
    char c = s[0];
    string ans = removeDup(s.substr(1));
    if (c == ans[0])
        return ans;
    else
    {
        return c + ans;
    }
}
string moveallXs(string s)
{
    // Time Complexity : O(n^2)
    // Space Complexity : O(n^2)
    if (s.length() == 0)
        return "";
    char c = s[0];
    string ans = moveallXs(s.substr(1));
    if (c == 'x')
        return ans + c;
    else
    {
        return c + ans;
    }
}
void subseq(string s, string ans = "")
{
    // Time Complexity : O(2^n)
    // Space Complexity : O(2^n)
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char c = s[0];
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ans + c);
}
void subseq2(string s, string ans = "")
{
    // Time Complexity : O(2^n)
    // Space Complexity : O(2^n)
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char c = s[0];
    int code = c;
    string ros = s.substr(1);
    subseq2(ros, ans);
    subseq2(ros, ans + c);
    subseq2(ros, ans + to_string(code));
}
string keypadArr[] = {"", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans = "")
{
    // Time Complexity : O(2^n)
    // Space Complexity : O(2^n)
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char c = s[0];
    string code = keypadArr[c - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
int main()
{
    reverse("Hailee");
    replacePi("pippxpixxpish");
    cout << removeDup("aaabbbdddcccdegggh");
    cout << moveallXs("xxvchdjxxbdjkxxyewu");
    subseq2("AB");
    keypad("23");
    return 0;
}