class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        unordered_map<int, int> m;
        int id = 0;
        m[id] = id;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] - nums[i-1] > maxDiff)
            {
                id = i;
            }
            m[i] = id;
        }
        vector<bool> ans(q.size(), 0);
        for (int i=0; i!=q.size(); i++)
        {
            if (m[q[i][0]] == m[q[i][1]]) ans[i] = 1;
        }
        return ans;
    }
};