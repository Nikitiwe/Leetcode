class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 1, ma = *max_element(nums.begin(), nums.end()), t = 1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == ma && nums[i-1] == ma)
            {
                t++;
                ans = max(ans, t);
            }
            else t = 1;
        }
        return ans;
    }
};