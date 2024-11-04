class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mi=nums[0], ans=-1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>mi) ans=max(ans, nums[i]-mi);
            mi=min(mi, nums[i]);
        }
        return ans;
    }
};