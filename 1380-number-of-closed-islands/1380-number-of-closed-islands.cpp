class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        int ans = 0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] == 0)
                {
                    queue<pair<int, int>> q;
                    unordered_set<int> s;
                    q.push({i, j});
                    s.insert(1000*i + j);
                    bool isit = 1;
                    while (q.size() > 0)
                    {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        g[x][y] = 1;
                        if (x == 0 || y == 0 || x == g.size() - 1 || y == g[0].size() - 1) isit = 0;
                        if (x > 0 && g[x-1][y] == 0 && s.count(1000*(x-1) + y) == 0)
                        {
                            q.push({x-1, y});
                            s.insert(1000*(x-1) + y);
                        }
                        if (y > 0 && g[x][y-1] == 0 && s.count(1000*(x) + y - 1) == 0)
                        {
                            q.push({x, y-1});
                            s.insert(1000*(x) + y - 1);
                        }
                        if (x < g.size() - 1 && g[x+1][y] == 0 && s.count(1000*(x+1) + y) == 0)
                        {
                            q.push({x+1, y});
                            s.insert(1000*(x+1) + y);
                        }
                        if (y < g[0].size() - 1 && g[x][y+1] == 0 && s.count(1000*(x) + y + 1) == 0)
                        {
                            q.push({x, y+1});
                            s.insert(1000*(x) + y + 1);
                        }
                    }
                    if (isit == 1) ans++;
                }
            }
        }
        return ans;
    }
};