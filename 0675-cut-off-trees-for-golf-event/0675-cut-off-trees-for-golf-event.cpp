class Solution {
public:
    int cutOffTree(vector<vector<int>>& g) {
        int ans = 0;
        int n = g.size(), m = g[0].size();
        vector<tuple<int, int, int>> arr; // высота, х, у
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=m; j++)
            {
                if (g[i][j] > 1) arr.push_back({g[i][j], i, j});
            }
        }
        arr.push_back({0, 0, 0});
        sort(arr.begin(), arr.end());
        for (int k=0; k+1<arr.size(); k++)
        {
            auto[end, x2, y2] = arr[k+1];
            auto[start, x1, y1] = arr[k];
            vector<vector<bool>> isit(n, vector<bool>(m, 1));
            queue<tuple<int, int, int>> q;
            q.push({x1, y1, 0});
            isit[x1][y1] = 0;
            bool next = 0;
            while (q.size() > 0)
            {
                auto[a, b, t] = q.front(); q.pop();
                if (g[a][b] == end)
                {
                    ans += t;
                    next = 1;
                    break;
                }
                if (a > 0 && g[a-1][b] > 0 && isit[a-1][b] == 1)
                {
                    q.push({a-1, b, t+1});
                    isit[a-1][b] = 0;
                }
                if (b > 0 && g[a][b-1] > 0 && isit[a][b-1] == 1)
                {
                    q.push({a, b-1, t+1});
                    isit[a][b-1] = 0;
                }
                if (a+1 < n && g[a+1][b] > 0 && isit[a+1][b] == 1)
                {
                    q.push({a+1, b, t+1});
                    isit[a+1][b] = 0;
                }
                if (b+1 < m && g[a][b+1] > 0 && isit[a][b+1] == 1)
                {
                    q.push({a, b+1, t+1});
                    isit[a][b+1] = 0;
                }
            }
            if (next == 0) return -1;
        }
        return ans;
    }
};