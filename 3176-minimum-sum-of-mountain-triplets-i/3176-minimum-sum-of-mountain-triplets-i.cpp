class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans=200;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size()-1; j++)
            {
                if (nums[i]<nums[j])
                {
                    for (int k=j+1; k<nums.size(); k++)
                    {
                        if (nums[j]>nums[k])
                        {
                            ans=min(ans, nums[i]+nums[j]+nums[k]);
                        }
                    }
                }
            }
        }
        if (ans==200) return -1;
        else return ans;
    }
};