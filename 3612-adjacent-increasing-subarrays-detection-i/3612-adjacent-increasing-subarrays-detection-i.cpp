class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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
        if (ans>=k) return 1;
        else return 0;
    }
};