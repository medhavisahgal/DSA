#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;
        int n = s.size();
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            m[s[i]] = i;
        }
        // debug statement
        //  for(auto x:m){
        //      cout<<x.first<<" "<<x.second<<endl;
        //  }
        cout << endl;
        int st = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            last = max(last, m[s[i]]);
            if (i == last)
            {
                res.push_back(last - st + 1);
                st = last + 1;
            }
        }
        return res;
    }
};
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Solution obj;
    vector<int> res = obj.partitionLabels(s);
    cout << "Partition Sizes: " << endl;
    for (int size : res)
    {
        cout << size << " ";
    }
    cout << endl;
    return 0;
}
