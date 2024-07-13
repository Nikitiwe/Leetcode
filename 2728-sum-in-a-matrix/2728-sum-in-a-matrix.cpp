class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans=0, tempi, m;
        for (int i=0; i!=nums[0].size(); i++)
        {
            m=0;
            for (int j=0; j!=nums.size(); j++)
            {
                tempi=0;
                for (int k=0; k!=nums[0].size(); k++)
                {
                    if (nums[j][k]>=nums[j][tempi]) tempi=k;
                }
                m=max(m, nums[j][tempi]);
                nums[j][tempi]=0;
            }
            ans+=m;
        }
        return ans;
    }
};