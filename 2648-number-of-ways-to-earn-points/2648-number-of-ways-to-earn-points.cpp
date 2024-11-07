class Solution {
public:
    int waysToReachTarget(int t, vector<vector<int>>& nums) {
        vector<long> ans(t+1, 0);
        ans[0]=1;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=t; j>=0; j--)
            {
                if (ans[j]>0)
                {
                    int s=j, l=1;
                    while (l<=nums[i][0]&&s+l*nums[i][1]<=t)
                    {
                        ans[s+l*nums[i][1]]+=ans[j];
                        ans[s+l*nums[i][1]]%=1000000007;
                        l++;
                    }
                }
            }
        }
        return ans.back();
    }
};