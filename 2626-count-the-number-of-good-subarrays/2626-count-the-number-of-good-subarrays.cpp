class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> m;
        long long c = 0;
        int l = 0;
        while (l < nums.size() && c < k)
        {
            m[nums[l]]++;
            c += m[nums[l]] - 1;
            l++;
        }
        if (c >= k) ans += nums.size() - l + 1;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]--;
            c -= m[nums[i]];
            while (l < nums.size() && c < k)
            {
                m[nums[l]]++;
                c += m[nums[l]] - 1;
                l++;
            }
            if (c >= k) ans += nums.size() - l + 1;
        }
        return ans;
    }
};