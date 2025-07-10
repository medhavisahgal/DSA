#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (window.count(nums[i]))
                return true;
            window.insert(nums[i]);
            if (window.size() > k)
            {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};