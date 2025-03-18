#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        // vector<vector<int>> nums3;
        // Merge common elements from nums1 and nums2
        // for (int i = 0; i < nums1.size(); i++)
        // {
        //     for (int j = 0; j < nums2.size(); j++)
        //     {
        //         if (nums1[i][0] == nums2[j][0])
        //         {
        //             int pushb = nums1[i][1] + nums2[j][1];
        //             nums3.push_back({nums1[i][0], pushb});
        //             break;
        //         }
        //     }
        // }

        // Insert unique elements from nums1
        // for (int i = 0; i < nums1.size(); i++)
        // {
        //     bool found = false;
        //     for (int j = 0; j < nums3.size(); j++)
        //     {
        //         if (nums1[i][0] == nums3[j][0])
        //         {
        //             found = true;
        //             break;
        //         }
        //     }
        //     if (!found)
        //     {
        //         nums3.push_back(nums1[i]);
        //     }
        // }

        // Insert unique elements from nums2
        // for (int i = 0; i < nums2.size(); i++)
        // {
        //     bool found = false;
        //     for (int j = 0; j < nums3.size(); j++)
        //     {
        //         if (nums2[i][0] == nums3[j][0])
        //         {
        //             found = true;
        //             break;
        //         }
        //     }
        //     if (!found)
        //     {
        //         nums3.push_back(nums2[i]);
        //     }
        // }
        // sort(nums3.begin(), nums3.end());
        // optimized approach - two pointer approach
        vector<vector<int>> nums3;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i][0] == nums2[j][0])
            {
                nums3.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (nums1[i][0] < nums2[j][0])
            {
                nums3.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else
            {
                nums3.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while (i < nums1.size())
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            nums3.push_back(nums2[j]);
            j++;
        }
        return nums3;
    }
};
