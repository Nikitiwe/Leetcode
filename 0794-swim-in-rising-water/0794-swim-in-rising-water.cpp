class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
        vector<vector<int>> arr(g.size(), vector<int> (g[0].size(), 10000));
        queue<int> x, y;
        x.push(0);
        y.push(0);
        arr[0][0] = g[0][0];
        while (x.size() > 0)
        {
            int a = x.front(); x.pop();
            int b = y.front(); y.pop();
            int t = arr[a][b];
            if (a > 0 && arr[a-1][b] > max(t, g[a-1][b]))
            {
                x.push(a-1);
                y.push(b);
                arr[a-1][b] = max(t, g[a-1][b]);
            }
            if (b > 0 && arr[a][b-1] > max(t, g[a][b-1]))
            {
                x.push(a);
                y.push(b-1);
                arr[a][b-1] = max(t, g[a][b-1]);
            }
            if (a+1 < g.size() && arr[a+1][b] > max(t, g[a+1][b]))
            {
                x.push(a+1);
                y.push(b);
                arr[a+1][b] = max(t, g[a+1][b]);
            }
            if (b+1 < g[0].size() && arr[a][b+1] > max(t, g[a][b+1]))
            {
                x.push(a);
                y.push(b+1);
                arr[a][b+1] = max(t, g[a][b+1]);
            }
        }
        return arr[g.size()-1][g[0].size()-1];
    }
};