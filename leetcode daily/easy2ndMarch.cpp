#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> nums3;

        // Merge common elements from nums1 and nums2
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i][0] == nums2[j][0])
                {
                    int pushb = nums1[i][1] + nums2[j][1];
                    nums3.push_back({nums1[i][0], pushb});
                    break;
                }
            }
        }

        // Insert unique elements from nums1
        for (int i = 0; i < nums1.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < nums3.size(); j++)
            {
                if (nums1[i][0] == nums3[j][0])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                nums3.push_back(nums1[i]);
            }
        }

        // Insert unique elements from nums2
        for (int i = 0; i < nums2.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < nums3.size(); j++)
            {
                if (nums2[i][0] == nums3[j][0])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                nums3.push_back(nums2[i]);
            }
        }

        // Sort by first element
        sort(nums3.begin(), nums3.end());

        return nums3;
    }
};
