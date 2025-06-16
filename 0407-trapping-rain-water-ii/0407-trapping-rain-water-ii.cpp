class Solution {
public:
    int trapRainWater(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> arr(n, vector<int>(m, 1e5));
        priority_queue<tuple<int, int, int>> q; // -высота + координаты
        for (int i=0; i!=n; i++)
        {
            q.push({ - g[i][0], i, 0});
            arr[i][0] = g[i][0];
            q.push({ - g[i][m-1], i, m-1});
            arr[i][m-1] = g[i][m-1];
        }
        for (int j=0; j!=m; j++)
        {
            q.push({ - g[0][j], 0, j});
            arr[0][j] = g[0][j];
            q.push({ - g[n-1][j], n-1, j});
            arr[n-1][j] = g[n-1][j];
        }
        while (q.size() > 0)
        {
            auto [h, x, y] = q.top();
            h *= -1;
            q.pop();
            if (x > 0 && x < n - 1 && y > 0 && y < m - 1)
            {
                if (h > g[x][y]) arr[x][y] = h - g[x][y];
                else arr[x][y] = 0;
            }
            if (x > 0 && arr[x-1][y] == 1e5)
            {
                q.push({ - max(h, g[x-1][y]), x-1, y});
                arr[x-1][y] = 1e5 - 1;
            }
            if (y > 0 && arr[x][y-1] == 1e5)
            {
                q.push({ - max(h, g[x][y-1]), x, y-1});
                arr[x][y-1] = 1e5 - 1;
            }
            if (x < n-1 && arr[x+1][y] == 1e5)
            {
                q.push({ - max(h, g[x+1][y]), x+1, y});
                arr[x+1][y] = 1e5 - 1;
            }
            if (y < m-1 && arr[x][y+1] == 1e5)
            {
                q.push({ - max(h, g[x][y+1]), x, y+1});
                arr[x][y+1] = 1e5 - 1;
            }
        }
        int ans = 0;
        for (int i=1; i<n-1; i++)
        {
            for (int j=1; j<m-1; j++) ans += arr[i][j];
        }
        return ans;
    }
};