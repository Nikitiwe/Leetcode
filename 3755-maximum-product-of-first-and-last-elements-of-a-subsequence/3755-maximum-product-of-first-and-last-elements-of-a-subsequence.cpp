class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = - 1e12;
        long long ma = nums[0], mi = nums[0];
        m--;
        for (int i=0; i!=nums.size(); i++)
        {
            if (i >= m)
            {
                ma = max(ma, (long long)nums[i-m]);
                mi = min(mi, (long long)nums[i-m]);

                ans = max(ans, nums[i]*ma);
                ans = max(ans, nums[i]*mi);
            }
        }
        return ans;
    }
};