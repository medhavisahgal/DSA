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
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         for (int k = j + 1; k < n; k++)
        //         {
        //             long long cal = nums[i] - nums[j];
        //             long long cal2 = cal * nums[k];
        //             maxtrip = max(maxtrip, cal2);
        //         }
        //     }
        // }
        // Time complexity is O(n^3) and space complexity is O(1)
        // Optimized approach
        // for(int k=2;k<n;k++){
        //     int mv=nums[0];
        //     for(int j=1;j<k;j++){
        //         long long cal = mv - nums[j];
        //         long long cal2 = cal * nums[k];
        //         maxtrip = max(maxtrip, cal2);
        //         mv=max(mv,nums[j]);
        //     }
        // }
        // Time complexity is O(n^2) and space complexity is O(1)
        // Optimized approach
        vector<int> left(n), right(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], nums[i + 1]);
        }

        long long maxtrip = 0;
        for (int i = 1; i < n - 1; i++)
        {
            long long cal = left[i] - nums[i];
            long long cal2 = cal * right[i + 1];
            maxtrip = max(maxtrip, cal2);
        }
        // Time complexity is O(n) and space complexity is O(n)
        return maxtrip;
    }
};