class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> m;
        int t = 0;
        m[t]++;
        for (int i=0; i!=nums.size(); i++)
        {
            t ^= nums[i];
            ans += m[t];
            m[t]++;
        }
        return ans;
    }
};