class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> arr(n, vector<int>(m, 2e9));
        priority_queue<tuple<int, int ,int ,int>> q; // -время, х, у
        q.push({ - 0, 0, 0, 1});
        arr[0][0] = 0;
        while (q.size() > 0)
        {
            auto [t, x, y, move] = q.top();
            q.pop();
            t *= -1;
            t += move;
            if (x > 0 && arr[x-1][y] > max(t, g[x-1][y]+move))
            {
                arr[x-1][y] = max(t, g[x-1][y]+move);
                q.push({ - max(t, g[x-1][y]+move), x-1, y, 3 - move});
            }
            if (y > 0 && arr[x][y-1] > max(t, g[x][y-1]+move))
            {
                arr[x][y-1] = max(t, g[x][y-1]+move);
                q.push({ - max(t, g[x][y-1]+move), x, y-1, 3 - move});
            }
            if (x+1 < n && arr[x+1][y] > max(t, g[x+1][y]+move))
            {
                arr[x+1][y] = max(t, g[x+1][y]+move);
                if (x+1 == n-1 && y == m-1) return max(t, g[x+1][y]+move);
                q.push({ - max(t, g[x+1][y]+move), x+1, y, 3 - move});
            }
            if (y+1 < m && arr[x][y+1] > max(t, g[x][y+1]+move))
            {
                arr[x][y+1] = max(t, g[x][y+1]+move);
                if (x == n-1 && y+1 == m-1) return max(t, g[x][y+1]+move);
                q.push({ - max(t, g[x][y+1]+move), x, y+1, 3 - move});
            }
        }
        return -1;
    }
};