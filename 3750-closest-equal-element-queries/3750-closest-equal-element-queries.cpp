class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
        vector<int> ans(q.size(), 1e9);
        unordered_map<int, int> s;
        for (int i=0; i!=q.size(); i++) s[q[i]] = i;
        unordered_map<int, int> l, r;
        for (int i=0; i!=nums.size(); i++)
        {
            if (s.count(i) == 1)
            {
                if (l.count(nums[i]) == 1) ans[s[i]] = min(ans[s[i]], n - i + l[nums[i]]);
                if (r.count(nums[i]) == 1) ans[s[i]] = min(ans[s[i]], i - r[nums[i]]);
            }
            if (l.count(nums[i]) == 0) l[nums[i]] = i;
            r[nums[i]] = i;
        }
        l.clear();
        r.clear();
        for (int i=n-1; i>=0; i--)
        {
            if (s.count(i) == 1)
            {
                if (r.count(nums[i]) == 1) ans[s[i]] = min(ans[s[i]], n - r[nums[i]] + i);
                if (l.count(nums[i]) == 1) ans[s[i]] = min(ans[s[i]], l[nums[i]] - i);
            }
            if (r.count(nums[i]) == 0) r[nums[i]] = i;
            l[nums[i]] = i;
        }
        for (int i=0; i!=ans.size(); i++) if (ans[i] == 1e9) ans[i] = -1;
        return ans;
    }
};