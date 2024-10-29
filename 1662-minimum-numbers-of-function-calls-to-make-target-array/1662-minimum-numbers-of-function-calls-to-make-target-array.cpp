class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0, d=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=0;
            while (nums[i]>0)
            {
                ans+=nums[i]%2;
                nums[i]-=nums[i]%2;
                if (nums[i]>0)
                {
                    nums[i]/=2;
                    t++;
                }
            }
            d=max(d, t);
        }
        return ans+d;
    }
};