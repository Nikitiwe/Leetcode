class Solution {
public:
    /*int minimumTime(vector<vector<int>>& g) {
        if (g[0][1] > 1 && g[1][0] > 1) return -1;
        deque<int> x, y;
        vector<vector<int>> ans(g.size(), vector<int>(g[0].size(), 1000000000));
        if (g[0][1] <= 1 )
        {
            ans[0][1] = 1;
            x.push_back(0);
            y.push_back(1);
        }
        if (g[1][0] <= 1 )
        {
            ans[1][0] = 1;
            x.push_back(1);
            y.push_back(0);
        }
        ans[0][0] = 0;
        x.push_back(0);
        y.push_back(0);
        
        while (x.size() > 0)
        {
            int a = x.front(); x.pop_front();
            int b = y.front(); y.pop_front();
            int t = ans[a][b];
            if (a > 0 && ans[a-1][b] > g[a-1][b] && ans[a-1][b] > t+1 )
            {
                if ((g[a-1][b] + t)%2 == 1) ans[a-1][b] = max(t+1, g[a-1][b]);
                else ans[a-1][b] = max(t+1, g[a-1][b] + 1);
                x.push_back(a-1);
                y.push_back(b);
            }
            if (b > 0 && ans[a][b-1] > g[a][b-1] && ans[a][b-1] > t+1 )
            {
                if ((g[a][b-1] + t)%2 == 1) ans[a][b-1] = max(t+1, g[a][b-1]);
                else ans[a][b-1] = max(t+1, g[a][b-1] + 1);
                x.push_back(a);
                y.push_back(b-1);
            }
            if (a+1 < g.size() && ans[a+1][b] > g[a+1][b] && ans[a+1][b] > t+1 )
            {
                if ((g[a+1][b] + t)%2 == 1) ans[a+1][b] = max(t+1, g[a+1][b]);
                else ans[a+1][b] = max(t+1, g[a+1][b] + 1);
                x.push_back(a+1);
                y.push_back(b);
            }
            if (b+1 < g[0].size() && ans[a][b+1] > g[a][b+1] && ans[a][b+1] > t+1 )
            {
                if ((g[a][b+1] + t)%2 == 1) ans[a][b+1] = max(t+1, g[a][b+1]);
                else ans[a][b+1] = max(t+1, g[a][b+1] + 1);
                x.push_back(a);
                y.push_back(b+1);
            }
        }
        return ans[g.size()-1][g[0].size()-1];
    }*/

        int minimumTime(vector<vector<int>>& g) {
        if (g[0][1] > 1 && g[1][0] > 1) return -1;
        int n = g.size(), m = g[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1000000000));

        // priority_queue: (время, x, y)
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        if (g[0][1] <= 1) {
            ans[0][1] = 1;
            pq.emplace(1, 0, 1);
        }
        if (g[1][0] <= 1) {
            ans[1][0] = 1;
            pq.emplace(1, 1, 0);
        }
        ans[0][0] = 0;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            auto [t, a, b] = pq.top(); pq.pop();
            if (t > ans[a][b]) continue;

            if (a > 0 && ans[a-1][b] > g[a-1][b] && ans[a-1][b] > t+1) {
                int nt = (g[a-1][b] + t) % 2 == 1 ? max(t+1, g[a-1][b]) : max(t+1, g[a-1][b] + 1);
                if (ans[a-1][b] > nt) {
                    ans[a-1][b] = nt;
                    pq.emplace(nt, a-1, b);
                }
            }
            if (b > 0 && ans[a][b-1] > g[a][b-1] && ans[a][b-1] > t+1) {
                int nt = (g[a][b-1] + t) % 2 == 1 ? max(t+1, g[a][b-1]) : max(t+1, g[a][b-1] + 1);
                if (ans[a][b-1] > nt) {
                    ans[a][b-1] = nt;
                    pq.emplace(nt, a, b-1);
                }
            }
            if (a+1 < n && ans[a+1][b] > g[a+1][b] && ans[a+1][b] > t+1) {
                int nt = (g[a+1][b] + t) % 2 == 1 ? max(t+1, g[a+1][b]) : max(t+1, g[a+1][b] + 1);
                if (ans[a+1][b] > nt) {
                    ans[a+1][b] = nt;
                    pq.emplace(nt, a+1, b);
                }
            }
            if (b+1 < m && ans[a][b+1] > g[a][b+1] && ans[a][b+1] > t+1) {
                int nt = (g[a][b+1] + t) % 2 == 1 ? max(t+1, g[a][b+1]) : max(t+1, g[a][b+1] + 1);
                if (ans[a][b+1] > nt) {
                    ans[a][b+1] = nt;
                    pq.emplace(nt, a, b+1);
                }
            }
        }
        return ans[g.size()-1][g[0].size()-1];
    }
};

