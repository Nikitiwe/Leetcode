class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 1, t = nums[0];
        for (int i = 1; i<nums.size(); i++)
        {
            if (nums[i] >= t) ans++;
            t = max(t, nums[i]);
        }
        return ans;
    }
};