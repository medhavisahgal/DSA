#include <iostream>
#include <string>
#include <climits>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        // ingore white spaces
        string s1 = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                s1 = s.substr(i);
                break;
            }
        }
        string s2 = "";
        if (s1.empty() || !(s1[0] == '+' || s1[0] == '-' || isdigit(s1[0])))
        {
            return 0;
        }
        s2.push_back(s1[0]);
        for (int i = 1; i < n; i++)
        {
            if (isdigit(s1[i]))
            {
                s2.push_back(s1[i]);
            }
            else
            {
                break;
            }
        }
        if (s2 == "+" || s2 == "-")
        {
            return 0;
        }
        try
        {
            long result = stol(s2);
            if (result >= INT_MAX)
                return INT_MAX;
            if (result <= INT_MIN)
                return INT_MIN;
            return static_cast<int>(result);
        }
        catch (const out_of_range &)
        {
            return s2[0] == '-' ? INT_MIN : INT_MAX;
        }
    }
};