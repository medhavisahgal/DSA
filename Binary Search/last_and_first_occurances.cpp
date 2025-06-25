#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int first_occur = -1;
        int last_occur = -1;
        while (left <= right)
        {
            int mid = right - (right - left) / 2;
            if (nums[mid] == target)
            {
                last_occur = max(last_occur, mid);
                left = left + 1;
            }
            else if (nums[mid] > target)
            {
                right = right - 1;
            }
            else if (nums[mid] < target)
            {
                left = left + 1;
            }
        }
        if (last_occur != -1)
        {
            first_occur = last_occur;
            left = 0;
            right = n - 1;
            while (left <= right)
            {
                int mid = right - (right - left) / 2;
                if (nums[mid] == target)
                {
                    first_occur = min(first_occur, mid);
                    right = right - 1;
                }
                else if (nums[mid] > target)
                {
                    right = right - 1;
                }
                else if (nums[mid] < target)
                {
                    left = left + 1;
                }
            }
        }
        ans.push_back(first_occur);
        ans.push_back(last_occur);
        return ans;
    }
};