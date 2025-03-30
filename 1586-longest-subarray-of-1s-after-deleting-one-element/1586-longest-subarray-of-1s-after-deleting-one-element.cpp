class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> l(nums.size(), 0), r = l;
        int t = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            l[i] = t;
            if (nums[i] == 1) t++;
            else t = 0;
        }
        t = 0;
        for (int i=nums.size()-1; i>=0; i--)
        {
            r[i] = t;
            if (nums[i] == 1) t++;
            else t = 0;
        }
        int ans = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            ans = max(ans, l[i]+r[i]);
        }
        return ans;
    }
};