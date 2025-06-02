class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        long long p = nums[0]+nums[1], m = nums[0]-nums[1];
        for (int i=2; i<nums.size(); i++)
        {
            long long a = max(p + nums[i], m + nums[i]);
            long long b = max(p - nums[i], m + nums[i]);
            p = a;
            m = b;
        }
        return max(p, m);
    }
};