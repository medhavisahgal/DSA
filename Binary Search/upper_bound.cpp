#include <vector>
using namespace std;
class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        int n = arr.size();
        int right = n - 1;
        int left = 0;
        int ans = n;
        while (right >= left)
        {
            int mid = right - (right - left) / 2;
            if (arr[mid] > target)
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
// upper bound is the first index where you get element greater than the target element
