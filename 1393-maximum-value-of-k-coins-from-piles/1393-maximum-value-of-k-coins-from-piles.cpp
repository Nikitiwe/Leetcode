class Solution {
public:
    unordered_map<int, int> m;
    int g(int k, int l) {return 1024*k + l; }

    int f(vector<vector<int>>& nums, int k, int l)
    {
        if (l == nums.size() || k == 0) return 0;
        int t = 0;
        if (m.count(g(k, l+1)) == 0) m[g(k, l+1)] = f(nums, k, l+1);
        int res = m[g(k, l+1)];
        for (int i=0; i!=nums[l].size(); i++)
        {
            t += nums[l][i];
            k--;
            if (m.count(g(k, l+1)) == 0) m[g(k, l+1)] = f(nums, k, l+1);
            res = max(res, t + m[g(k, l+1)]);
            if (k == 0) break;
        }
        return res;
    }

    int maxValueOfCoins(vector<vector<int>>& nums, int k) {
        return f(nums, k, 0);
    }
};