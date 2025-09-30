class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ma = nums[0], mi = nums[0];
        for (int i=0; i!=nums.size(); i++)
        {
            ma = max(ma, nums[i]);
            mi = min(mi, nums[i]);
        }
        return (long long)k*(ma - mi);
    }
};