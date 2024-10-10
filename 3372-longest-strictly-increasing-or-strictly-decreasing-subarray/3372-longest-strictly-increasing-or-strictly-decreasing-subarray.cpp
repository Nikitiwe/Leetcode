class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int u=1, d=1, ans=1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]<nums[i])
            {
                u++;
                ans=max(ans, u);
                d=1;
            }
            else if (nums[i-1]>nums[i])
            {
                d++;
                ans=max(ans, d);
                u=1;
            }
            else
            {
                u=1;
                d=1;
            }
        }
        return ans;
    }
};