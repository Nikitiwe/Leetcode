class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long> ans(nums.size(), 0);
        if (nums[0]<k) ans[0]=k-nums[0];
        if (nums[1]<k) ans[1]=k-nums[1];
        if (nums[2]<k) ans[2]=k-nums[2];
        for (int i=3; i<nums.size(); i++)
        {
            ans[i]=+min({ans[i-1], ans[i-2], ans[i-3]});
            if (nums[i]<k) ans[i]+=k-nums[i];
        }
        return min({ans[nums.size()-1], ans[nums.size()-2], ans[nums.size()-3]});
    }
};