#include <vector>

using namespace std;

class Solution
{
public:
    bool ceit(vector<int> &piles, int k, int h)
    {
        long long hr = 0;
        for (int x : piles)
        {
            int d = x / k;
            hr += d;
            if (x % k != 0)
            {
                hr++;
            }
        }
        return hr <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // return minimum k such that she can eat all the bananas within h hours
        int n = piles.size();
        int left = 1;
        int right = 1000000000;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (ceit(piles, mid, h))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};