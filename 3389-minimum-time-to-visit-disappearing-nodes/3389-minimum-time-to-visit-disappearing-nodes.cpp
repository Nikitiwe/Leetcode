class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& e, vector<int>& d) {
        vector<int> time(n, 1e9);
        time[0] = 0;
        vector<vector<pair<int, int>>> arr(n, vector<pair<int, int>>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back({e[i][1], e[i][2]});
            arr[e[i][1]].push_back({e[i][0], e[i][2]});
        }
        priority_queue<pair<int, int>> q; // - время + id
        q.push({ - 0, 0});
        while (q.size() > 0)
        {
            int t = - q.top().first;
            int id = q.top().second;
            q.pop();
            if (t > time[id]) continue;
            if (t >= d[id]) continue;
            {
                for (int i=0; i<arr[id].size(); i++)
                {
                    if (d[arr[id][i].first] > t + arr[id][i].second && time[arr[id][i].first] > t + arr[id][i].second)
                    {
                        time[arr[id][i].first] = t + arr[id][i].second;
                        q.push({ - t - arr[id][i].second, arr[id][i].first});
                    }
                }
            }
        }
        for (int i=0; i!=n; i++)
        {
            if (time[i] >= d[i]) time[i] = -1;
        }
        return time;
    }
};