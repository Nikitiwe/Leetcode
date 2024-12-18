class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int k) {
        int ans=0, t=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]>k)
            {
                ans=max(ans, t);
                t=0;
            }
            else
            {
                if (t==0)
                {
                    if (nums[i]%2==0) t++;
                }
                else
                {
                    if (nums[i]%2==t%2) t++;
                    else
                    {
                        ans=max(ans, t);
                        t=0;
                        if (nums[i]%2==0) t++;
                    }
                }
            }
        }
        ans=max(ans, t);
        return ans;
    }
};