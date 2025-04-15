class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& nums, vector<int>& add) {
        unordered_map<int, int> h, r;
        vector<vector<int>> arr(n+1);
        for (int i=0; i!=nums.size(); i++)
        {
            r[nums[i][1]]++;
            arr[nums[i][0]].push_back(nums[i][1]);
        }
        int ans = 0;
        priority_queue<pair<int, int>> tc; // time + course
        for (int i=1; i<=n; i++) if (r[i] == 0) tc.push({-add[i-1], i});
        while (tc.size() > 0)
        {
            int t = -tc.top().first, c = tc.top().second;
            tc.pop();
            ans = max(ans, t);
            for (int i=0; i<arr[c].size(); i++)
            {
                h[arr[c][i]]++;
                if (h[arr[c][i]] == r[arr[c][i]])
                {
                    tc.push({-add[arr[c][i]-1]-t, arr[c][i]});
                }
            }
        }
        return ans;
    }
};