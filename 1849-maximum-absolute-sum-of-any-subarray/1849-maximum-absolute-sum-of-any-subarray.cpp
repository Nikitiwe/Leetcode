class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int sm = 0, sp = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                sp = max(nums[i], sp+nums[i]);
                ans = max(ans, sp);
                sm -= nums[i];
            }
            else if (nums[i] < 0)
            {
                sm = max(-nums[i], sm-nums[i]);
                ans = max(ans, sm);
                sp += nums[i];
            }
        }
        return ans;
    }
};