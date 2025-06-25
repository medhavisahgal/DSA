#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &arr, int target)
    {
        int n = arr.size();
        int right = n - 1;
        int left = 0;
        int ans = n;
        while (left <= right)
        {
            int mid = right - (right - left) / 2;
            if (arr[mid] >= target)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
// lower bound is the first index where the value is greater than or equal to target