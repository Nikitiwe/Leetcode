class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long> arr(nums.size(), 0);
        vector<vector<long long>> ans(nums.size(), vector<long long> (3, 0));
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]<k) arr[i]=k-nums[i];
        }
        ans[0][0]=arr[0]; ans[0][1]=9999999; ans[0][2]=9999999;
        ans[1][0]=arr[1]; ans[1][1]=arr[0]; ans[1][2]=9999999;
        ans[2][0]=arr[2]; ans[2][1]=arr[1]; ans[2][2]=arr[0];
        for (int i=3; i<nums.size(); i++)
        {
            ans[i][0]=arr[i]+min({ans[i-1][0], ans[i-1][1], ans[i-1][2]});
            ans[i][1]=ans[i-1][0];
            ans[i][2]=ans[i-2][0];
        }
        return min({ans[nums.size()-1][0], ans[nums.size()-1][1], ans[nums.size()-1][2]});
    }
};