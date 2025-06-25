#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findFloor(vector<int> &arr, int target)
    {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = right - (right - left) / 2;
            if (arr[mid] <= target)
            {
                ans = max(ans, mid);
                left = left + 1;
            }
            else
            {
                right = right - 1;
            }
        }
        return ans;
    }
};
