class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=-1;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=nums[i];
            for (int j=1; j<nums.size()-i; j++)
            {
                if (j%2==1)
                {
                    if (nums[i+j]==t+1) ans=max(ans, j+1);
                    else break;
                }
                else
                {
                    if (nums[i+j]==t) ans=max(ans, j+1);
                    else break;
                }
            }
        }
        return ans;
    }
};