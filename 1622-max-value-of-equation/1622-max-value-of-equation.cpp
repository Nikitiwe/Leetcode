class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        priority_queue<pair<int, int>> q;
        int ans = -2000000000;
        for (int i=0; i!=p.size(); i++)
        {
            while (q.size() > 0 && p[i][0] - q.top().second > k) q.pop();
            if (q.size() > 0) ans = max(ans, p[i][1] + p[i][0] + q.top().first);
            q.push({p[i][1] - p[i][0], p[i][0]});
        }
        return ans;
    }
};