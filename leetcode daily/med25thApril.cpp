#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int mod, int k)
    {
        // brute force;
        //  long long n=nums.size();
        //  long long cnt1=0;
        //  for(long long i=0;i<n;i++){
        //      vector<long long>temp;
        //      for(long long j=i;j<n;j++){
        //          long long cnt=0;
        //          temp.push_back(nums[j]);
        //          for(long long x:temp){
        //              if(x%mod==k){
        //                  cnt++;
        //              }
        //          }
        //          if(cnt%mod==k){
        //              cnt1++;
        //          }
        //      }
        //  }
        unordered_map<int, long long> mp;
        mp[0] = 1;
        long long cnt = 0, res = 0;
        long long n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % mod == k)
            {
                cnt++;
            }
            int want = (cnt - k + mod) % mod;
            res += mp[want];
            mp[cnt % mod]++;
        }
        return res;
    }
};