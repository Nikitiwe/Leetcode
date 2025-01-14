class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        vector<int> ans(nums.size(), 10000000);
        ans.back()=nums.back();
        ans[ans.size()-2]=nums[nums.size()-2];
        for (int i=nums.size()-3; i>=0; i--)
        {
            ans[i]=nums[i]+min(ans[i+1], ans[i+2]);
        }
        return min(ans[0], ans[1]);
    }
};