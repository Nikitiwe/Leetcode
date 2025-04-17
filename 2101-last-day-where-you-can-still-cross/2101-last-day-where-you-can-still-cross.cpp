class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& c) {
        int ans = 0, l = 0, r = c.size(), m;
        while (l <= r)
        {
            m = (l+r)/2;
            vector<vector<int>> g(row, vector<int>(col, 0));
            for (int i=0; i<m; i++) g[c[i][0]-1][c[i][1]-1] = 2;
            bool isit = 0;
            queue<int> x, y;
            for (int j=0; j<col; j++) if (g[0][j] != 2)
            {
                x.push(0);
                y.push(j);
                g[0][j] = 1;
            }
            while (x.size() > 0)
            {
                int a = x.front(); x.pop();
                int b = y.front(); y.pop();
                if (a == row - 1)
                {
                    isit = 1;
                    break;
                }
                if (a > 0 && g[a-1][b] == 0)
                {
                    x.push(a-1);
                    y.push(b);
                    g[a-1][b] = 1;
                }
                if (b > 0 && g[a][b-1] == 0)
                {
                    x.push(a);
                    y.push(b-1);
                    g[a][b-1] = 1;
                }
                if (a+1 < row && g[a+1][b] == 0)
                {
                    x.push(a+1);
                    y.push(b);
                    g[a+1][b] = 1;
                }
                if (b+1 < col && g[a][b+1] == 0)
                {
                    x.push(a);
                    y.push(b+1);
                    g[a][b+1] = 1;
                }
            }
            if (isit == 1)
            {
                ans = max(ans, m);
                l = m + 1;
            }
            else r = m-1;
        }
        return ans;
    }
};