#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        // my approach
        //  map<int,int>m;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        // }
        // for(auto x:m){
        //     if(x.second%2!=0){
        //         return false;
        //     }
        // }
        // return true;
        // hash set approach
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (s.count(nums[i]))
            { // if count of that  number is not zero
                s.erase(nums[i]);
            }
            else
            {
                s.insert(nums[i]); // if zero insert
            }
        }
        return s.empty();
    }
};