#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> ne;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ne.push_back(nums[i]);
                cnt++;
            }
        }
        while (cnt < n)
        {
            ne.push_back(0);
            cnt++;
        }
        return ne;
    }
};