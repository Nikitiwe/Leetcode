class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        vector<vector<long>> ans(nums.size(), vector<long> (3, 0));
        if (nums[0]==0) ans[0][0]++;
        for (int i=1; i<nums.size(); i++)
        {
            ans[i][0]=ans[i-1][0];
            ans[i][1]=ans[i-1][1];
            ans[i][2]=ans[i-1][2];
            if (nums[i]==0)
            {
                ans[i][0]++;
                ans[i][0]+=ans[i-1][0];
                ans[i][0]%=1000000007;
            }
            else if (nums[i]==1)
            {
                ans[i][1]+=ans[i-1][0];
                ans[i][1]+=ans[i-1][1];
                ans[i][1]%=1000000007;
            }
            else
            {
                ans[i][2]+=ans[i-1][1];
                ans[i][2]+=ans[i-1][2];
                ans[i][2]%=1000000007;
            }
        }
        return ans[nums.size()-1][2];
    }
};