class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int ans = 0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] == 1)
                {
                    int t = 0;
                    queue<pair<int, int>> q;
                    unordered_set<int> s;
                    q.push({i, j});
                    s.insert(i*100 + j);
                    while (q.size() > 0)
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (g[x][y] == 1)
                        {
                            g[x][y] = 0;
                            t++;
                        }
                        if (x-1>=0 && g[x-1][y] == 1 && s.count(100*(x-1) + y) == 0) {q.push({x-1, y}); s.insert(100*(x-1) + y);}
                        if (y-1>=0 && g[x][y-1] == 1 && s.count(100*(x) + y-1) == 0) {q.push({x, y-1}); s.insert(100*(x) + y-1);}
                        if (x+1<g.size() && g[x+1][y] == 1 && s.count(100*(x+1) + y) == 0) {q.push({x+1, y}); s.insert(100*(x+1) + y);}
                        if (y+1<g[0].size() && g[x][y+1] == 1 && s.count(100*(x) + y+1) == 0) {q.push({x, y+1}); s.insert(100*(x) + y+1);}
                    }
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};