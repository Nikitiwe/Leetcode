class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        queue<pair<int, int>> q;
        unordered_set<int> s;
        for (int i=0; i!=g.size(); i++) if (g[i][0] == 1)
        {
            q.push({i, 0});
            s.insert(1000*i);
        }
        for (int i=0; i!=g.size(); i++) if (g[i][g[0].size()-1] == 1)
        {
            q.push({i, g[0].size()-1});
            s.insert(1000*i + g[0].size()-1);
        }
        for (int j=0; j!=g[0].size(); j++) if (g[0][j] == 1)
        {
            q.push({0, j});
            s.insert(j);
        }
        for (int j=0; j!=g[0].size(); j++) if (g[g.size()-1][j] == 1)
        {
            q.push({g.size()-1, j});
            s.insert(1000*(g.size()-1) + j);
        }
        while (q.size() > 0)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            g[x][y] = 0;
            if (x > 0 && g[x-1][y] == 1 && s.count(1000*(x-1) + y) == 0)
            {
                q.push({x-1, y});
                s.insert(1000*(x-1) + y);
            }
            if (y > 0 && g[x][y-1] == 1 && s.count(1000*(x) + y - 1) == 0)
            {
                q.push({x, y-1});
                s.insert(1000*(x) + y - 1);
            }
            if (x < g.size()-1 && g[x+1][y] == 1 && s.count(1000*(x+1) + y) == 0)
            {
                q.push({x+1, y});
                s.insert(1000*(x+1) + y);
            }
            if (y < g[0].size() - 1 && g[x][y+1] == 1 && s.count(1000*(x) + y + 1) == 0)
            {
                q.push({x, y+1});
                s.insert(1000*(x) + y + 1);
            }
        }
        int ans = 0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++) ans += g[i][j];
        }
        return ans;
    }
};