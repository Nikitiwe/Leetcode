class Solution {
public:
    int numSubseq(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0, mod = 1000000007;
        vector<int> add;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            if (nums[l] + nums[r] <= k)
            {
                add.push_back(r-l);
                l++;
            }
            else r--;
        }
        long long mn = 1;
        int st = 0;
        for (int i=add.size()-1; i>=0; i--)
        {
            while (st < add[i])
            {
                mn *= 2;
                mn %= mod;
                st++;
            }
            ans += mn;
            ans %= mod;
        }
        return ans;
    }
};