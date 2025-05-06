class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0, mod = 1e9 + 7, mn = 1;
        for (int i=0; i!=nums.size(); i++)
        {
            ans += (long long)nums[i] * mn;
            ans %= mod;
            mn *= 2;
            mn %= mod;
        }
        mn = 1;
        for (int i=nums.size()-1; i>=0; i--)
        {
            ans -= ((long long)nums[i] * mn) % mod;
            ans = (ans + mod) % mod;
            //ans %= mod;
            mn *= 2;
            mn %= mod;
        }
        return ans;
    }
};