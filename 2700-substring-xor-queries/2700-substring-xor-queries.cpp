class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        unordered_map<long, pair<int, int>> m;
        long mi = INT_MAX;
        for (int i=0; i!=s.size(); i++)
        {
            long t = 0;
            for (int j=i; j<s.size(); j++)
            {
                t *= 2;
                t += s[j] - '0';
                if (t >= mi) break;
                if (j - i >= 31) break;
                if (m.count(t) == 0) m[t] = {i, j};
                else
                {
                    if (m[t].second - m[t].first > j - i) m[t] = {i, j};
                    else if (m[t].second - m[t].first == j - i && i < m[t].first) m[t] = {i, j};
                }
            }
        }
        vector<vector<int>> ans(q.size(), {-1, -1});
        for (int i=0; i!=q.size(); i++)
        {
            int t = q[i][0] ^ q[i][1];
            if (m.count(t) != 0)
            {
                ans[i][0] = m[t].first;
                ans[i][1] = m[t].second;
            }
        }
        return ans;
    }
};