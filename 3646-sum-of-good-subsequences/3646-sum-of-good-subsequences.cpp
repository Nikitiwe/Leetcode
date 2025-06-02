class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        long ans = 0, mod = 1e9 + 7;
        unordered_map<int, long> m, c;
        for (int i=0; i!=nums.size(); i++)
        {
            long add = nums[i] + c[nums[i]-1] * nums[i] + c[nums[i]+1] * nums[i] + m[nums[i]-1] + m[nums[i]+1];
            c[nums[i]] += c[nums[i]-1] + c[nums[i]+1] + 1;
            c[nums[i]] %= mod;
            m[nums[i]] += add;
            m[nums[i]] %= mod;
            ans += add;
            ans %= mod;
        }
        return ans;
    }
};