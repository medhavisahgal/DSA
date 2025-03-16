#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // objective is to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock
        // brute force
        int n = prices.size();
        int maxdiff = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int absdiff = 0;
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         absdiff = prices[j] - prices[i];
        //         maxdiff = max(maxdiff, absdiff);
        //     }
        // }
        // You will get tle in brute force because Time Complexity is O(N^2) and N can be 10^5 so that means N^2 can be 10^10  which is impossible to run in 1 sec .
        // Sliding window approach - variable size window
        int left = 0, right = 1;
        while (right < n)
        {
            int absdiff = prices[right] - prices[left];
            if (prices[left] < prices[right])
            {
                maxdiff = max(maxdiff, absdiff);
            }
            else
            {
                left = right;
            }
            right++;
        }

        return maxdiff;
    }
};