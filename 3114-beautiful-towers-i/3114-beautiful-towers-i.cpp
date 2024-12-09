class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        long long ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=nums[i];
            long long s=t;
            for (int j=i+1; j<nums.size(); j++)
            {
                t=min(t, nums[j]);
                s+=t;
            }
            t=nums[i];
            for (int j=i-1; j>=0; j--)
            {
                t=min(t, nums[j]);
                s+=t;
            }
            ans=max(ans, s);
        }
        return ans;
    }
};