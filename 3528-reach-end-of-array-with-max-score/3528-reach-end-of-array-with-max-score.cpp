class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0, l=0;
        for (int i=1; i<nums.size()-1; i++)
        {
            if (nums[i]>nums[l])
            {
                ans+=(i-l)*nums[l];
                l=i;
            }
        }
        ans+=(nums.size()-1-l)*nums[l];
        return ans;
    }
};