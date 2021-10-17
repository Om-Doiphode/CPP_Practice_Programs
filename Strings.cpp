#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string text = "FEHKEKTGJHG";

    // Converting uppercase to lowercase
    for (int i = 0; i < text.length(); i++)
    {
        text[i] += 32;
    }
    cout << "LOWERCASE : " << text << endl;

    // Converting lowercase to uppercase
    for (int i = 0; i < text.length(); i++)
    {
        text[i] -= 32;
    }
    cout << "UPPERCASE : " << text << endl;

    // To find the repeating letter in a string
    int freq[26];
    int maxfreq = -19999;
    char ans;

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < text.length(); i++)
    {
        freq[text[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (maxfreq < freq[i])
        {
            maxfreq = freq[i];
            ans = i + 'a';
        }
    }
    cout << maxfreq << " " << ans << endl;
    return 0;
}