class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long> arr(nums.size(), 0);
        vector<long long> ans(nums.size(), 0);
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]<k) arr[i]=k-nums[i];
        }
        ans[0]=arr[0];
        ans[1]=arr[1];
        ans[2]=arr[2];
        for (int i=3; i<nums.size(); i++)
        {
            ans[i]=arr[i]+min({ans[i-1], ans[i-2], ans[i-3]});
        }
        return min({ans[nums.size()-1], ans[nums.size()-2], ans[nums.size()-3]});
    }
};