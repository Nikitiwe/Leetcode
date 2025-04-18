class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        vector<vector<int>> ans(g.size(), vector<int> (g[0].size(), 1000000000));
        queue<int> x, y;
        x.push(0);
        y.push(0);
        ans[0][0] = 0;
        while (x.size() > 0)
        {
            int a = x.front(); x.pop();
            int b = y.front(); y.pop();
            int t = ans[a][b];
            if (a > 0 && max(abs(g[a-1][b] - g[a][b]), t) < ans[a-1][b])
            {
                x.push(a-1);
                y.push(b);
                ans[a-1][b] = max(abs(g[a-1][b] - g[a][b]), t);
            }
            if (b > 0 && max(abs(g[a][b-1] - g[a][b]), t) < ans[a][b-1])
            {
                x.push(a);
                y.push(b-1);
                ans[a][b-1] = max(abs(g[a][b-1] - g[a][b]), t);
            }
            if (a+1 < g.size() && max(abs(g[a+1][b] - g[a][b]), t) < ans[a+1][b])
            {
                x.push(a+1);
                y.push(b);
                ans[a+1][b] = max(abs(g[a+1][b] - g[a][b]), t);
            }
            if (b+1 < g[0].size() && max(abs(g[a][b+1] - g[a][b]), t) < ans[a][b+1])
            {
                x.push(a);
                y.push(b+1);
                ans[a][b+1] = max(abs(g[a][b+1] - g[a][b]), t);
            }
        }
        return ans[g.size() - 1][g[0].size() - 1];
    }
};