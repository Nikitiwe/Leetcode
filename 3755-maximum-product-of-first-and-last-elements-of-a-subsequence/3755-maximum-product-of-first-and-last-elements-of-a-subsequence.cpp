class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = - 1e12;
        set<long long> s;
        m--;
        for (int i=0; i!=nums.size(); i++)
        {
            if (i >= m) s.insert(nums[i-m]);
            if (s.size() > 0)
            {
                ans = max(ans, nums[i]*(*s.begin()));
                auto it = --s.end();
                ans = max(ans, nums[i]*(*it));
            }
        }
        return ans;
    }
};