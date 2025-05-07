class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> arr(n, vector<int>(m, 2e9));
        priority_queue<tuple<int, int ,int>> q; // -время, х, у
        q.push({ - 0, 0, 0});
        arr[0][0] = 0;
        while (q.size() > 0)
        {
            auto [t, x, y] = q.top();
            q.pop();
            t *= -1;
            t++;
            if (x > 0 && arr[x-1][y] > max(t, g[x-1][y]+1))
            {
                arr[x-1][y] = max(t, g[x-1][y]+1);
                q.push({ - max(t, g[x-1][y]+1), x-1, y});
            }
            if (y > 0 && arr[x][y-1] > max(t, g[x][y-1]+1))
            {
                arr[x][y-1] = max(t, g[x][y-1]+1);
                q.push({ - max(t, g[x][y-1]+1), x, y-1});
            }
            if (x+1 < n && arr[x+1][y] > max(t, g[x+1][y]+1))
            {
                arr[x+1][y] = max(t, g[x+1][y]+1);
                if (x+1 == n-1 && y == m-1) return max(t, g[x+1][y]+1);
                q.push({ - max(t, g[x+1][y]+1), x+1, y});
            }
            if (y+1 < m && arr[x][y+1] > max(t, g[x][y+1]+1))
            {
                arr[x][y+1] = max(t, g[x][y+1]+1);
                if (x == n-1 && y+1 == m-1) return max(t, g[x][y+1]+1);
                q.push({ - max(t, g[x][y+1]+1), x, y+1});
            }
        }
        return -1;
    }
};