class Solution {
public:
    int splitArray(vector<int>& nums, int kk) {
        vector<vector<int>> c(nums.size(), vector<int> (nums.size(), 0));
        for (int i=0; i!=nums.size(); i++)
        {
            int s=0;
            for (int j=i; j<nums.size(); j++)
            {
                s+=nums[j];
                c[i][j]=s;
            }
        }
        vector<int> ans=c[0];
        for (int k=1; k<kk; k++)
        {
            vector<int> t=ans;
            for (int i=k; i<nums.size(); i++)
            {
                for (int j=k; j<=i; j++)
                {
                    t[i]=min(t[i], max(ans[j-1], c[j][i]));
                }
            }
            ans=t;
        }
        return ans[nums.size()-1];
    }
};