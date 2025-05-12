class Solution {
public:
    int cutOffTree(vector<vector<int>>& g) {
        int ans = 0;
        vector<tuple<int, int, int>> arr; // высота, х, у
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
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
            vector<vector<bool>> isit(g.size(), vector<bool>(g[0].size(), 1));
            queue<int> x, y, l;
            x.push(x1);
            y.push(y1);
            l.push(0);
            isit[x1][y1] = 0;
            bool next = 0;
            while (x.size() > 0)
            {
                int a = x.front(); x.pop();
                int b = y.front(); y.pop();
                int t = l.front(); l.pop();
                if (g[a][b] == end)
                {
                    ans += t;
                    next = 1;
                    break;
                }
                if (a > 0 && g[a-1][b] > 0 && isit[a-1][b] == 1)
                {
                    x.push(a-1);
                    y.push(b);
                    l.push(t+1);
                    isit[a-1][b] = 0;
                }
                if (b > 0 && g[a][b-1] > 0 && isit[a][b-1] == 1)
                {
                    x.push(a);
                    y.push(b-1);
                    l.push(t+1);
                    isit[a][b-1] = 0;
                }
                if (a+1 < g.size() && g[a+1][b] > 0 && isit[a+1][b] == 1)
                {
                    x.push(a+1);
                    y.push(b);
                    l.push(t+1);
                    isit[a+1][b] = 0;
                }
                if (b+1 < g[0].size() && g[a][b+1] > 0 && isit[a][b+1] == 1)
                {
                    x.push(a);
                    y.push(b+1);
                    l.push(t+1);
                    isit[a][b+1] = 0;
                }
            }
            if (next == 0) return -1;
        }
        return ans;
    }
};