class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ans=0;
        sort(nums.begin(), nums.end());
        int idm=(nums.size())/2;
        if (nums[idm]>k)
        {
            for (int i=idm; i>=0; i--)
            {
                if (nums[i]>k) ans+=nums[i]-k;
                else break;
            }
        }
        else
        {
            for (int i=idm; i<nums.size(); i++)
            {
                if (nums[i]<k) ans+=k-nums[i];
                else break;
            }
        }
        return ans;
    }
};