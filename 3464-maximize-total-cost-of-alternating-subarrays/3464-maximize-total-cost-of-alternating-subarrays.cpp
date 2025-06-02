class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        //else if (nums.size() == 2) return max(nums[0]+nums[1], nums[0]-nums[1]);
        vector<long long> p(nums.size(), 0), m = p;
        p[0] = nums[0];
        p[1] = nums[0]+nums[1];
        m[1] = nums[0]-nums[1];
        for (int i=2; i<nums.size(); i++)
        {
            p[i] = max(p[i-1] + nums[i], m[i-1] + nums[i]);
            m[i] = max(p[i-1] - nums[i], m[i-1] + nums[i]);
        }
        return max(p.back(), m.back());
    }
};