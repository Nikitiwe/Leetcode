class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans=nums;
        for (int i=0; i!=nums.size(); i++)
        {
            ans[i]=nums[(i+nums[i]+100*nums.size())%nums.size()];
        }
        return ans;
    }
};