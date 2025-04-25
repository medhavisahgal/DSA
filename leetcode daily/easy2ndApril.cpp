#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maximumTripletValue(std::vector<int> &nums)
    {
        // brute force
        long long maxtrip = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    long long cal = nums[i] - nums[j];
                    long long cal2 = cal * nums[k];
                    maxtrip = max(maxtrip, cal2);
                }
            }
        }
        return maxtrip;
    }
};