class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                int s=nums[i]+nums[j];
                {
                    for (int a=j+1; a<nums.size(); a++)
                    {
                        int ss=s+nums[a];
                        for (int b=a+1; b<nums.size(); b++)
                        {
                            if (ss==nums[b]) ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};