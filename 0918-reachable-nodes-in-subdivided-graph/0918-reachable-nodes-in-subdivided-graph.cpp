class Solution {
public:
    int reachableNodes(vector<vector<int>>& e, int k, int n) {
        vector<int> d(n, 2000000000);
        d[0] = 0;
        int ans = 0;
        vector<vector<int>> arr(n, vector<int>()), r = arr;
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back(e[i][1]);
            r[e[i][0]].push_back(e[i][2] + 1);

            arr[e[i][1]].push_back(e[i][0]);
            r[e[i][1]].push_back(e[i][2] + 1);
        }
        priority_queue<pair<int, int>> q; // dist + id
        q.push({-0, 0});
        while (q.size() > 0)
        {
            int x = -q.top().first, id = q.top().second;
            q.pop();
            for (int i=0; i!=arr[id].size(); i++)
            {
                if (d[arr[id][i]] > x + r[id][i])
                {
                    d[arr[id][i]] = x + r[id][i];
                    q.push({-d[arr[id][i]], arr[id][i]});
                }
            }
        }
        for (int i=0; i!=d.size(); i++)
        {
            if (d[i] <= k) ans++;
        }
        int add = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            int a = 0;
            if (d[i] < k) a += k - d[i];
            for (int j=0; j!=arr[i].size(); j++)
            {
                int b = 0;
                if (d[arr[i][j]] < k) b += k - d[arr[i][j]];
                add += min(a + b, r[i][j] - 1);
            }
        }
        return ans + add/2;
    }
};