class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int t=1, ans=0, p=0;
        nums.push_back(-2000000000);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>nums[i-1]) t++;
            else
            {
                ans=max(ans, min(p, t));
                ans=max(ans, t/2);
                p=t;
                t=1;
            }
        }
        return ans;
    }
};