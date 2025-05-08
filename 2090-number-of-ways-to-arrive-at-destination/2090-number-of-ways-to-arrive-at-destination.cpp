class Solution {
public:
    int countPaths(int n, vector<vector<int>>& r) {
        vector<long> ans(n, 0);
        vector<long> t(n, 1e12);
        t[0] = 0;
        long mod = 1e9 + 7;
        ans[0] = 1;
        vector<vector<pair<int, int>>> arr(n, vector<pair<int, int>>());
        for (int i=0; i!=r.size(); i++)
        {
            arr[r[i][0]].push_back({r[i][1], r[i][2]});
            arr[r[i][1]].push_back({r[i][0], r[i][2]});
        }
        priority_queue<tuple<long, int>> q; // куда, за сколько и
        q.push({ - 0, 0});
        while (q.size() > 0)
        {
            auto[time, id] = q.top();
            q.pop();
            time *= -1;
            for (int j = 0; j<arr[id].size(); j++)
            {
                if (time + arr[id][j].second == t[arr[id][j].first])
                {
                    ans[arr[id][j].first] += ans[id];
                    ans[arr[id][j].first] %= mod;
                    //q.push({ - 0, 0, 1});
                }
                else if (time + arr[id][j].second < t[arr[id][j].first])
                {
                    t[arr[id][j].first] = time + arr[id][j].second;
                    ans[arr[id][j].first] = ans[id];
                    ans[arr[id][j].first] %= mod;
                    q.push({ - time - arr[id][j].second, arr[id][j].first});
                }
            }
        }
        return ans.back();
    }
};