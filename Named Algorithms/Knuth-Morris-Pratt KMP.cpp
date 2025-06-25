#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> computeLPS(string pattern)
{
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // Try a smaller prefix
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int KMP(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            return i - j; // Match found
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1;
}
int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";
    int result = KMP(text, pattern);
    if (result != -1)
        cout << "Pattern found at index: " << result << endl;
    else
        cout << "Pattern not found" << endl;
    return 0;
}
