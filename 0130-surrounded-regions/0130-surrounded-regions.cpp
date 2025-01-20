class Solution {
public:
    void solve(vector<vector<char>>& g) {
        stack<pair<int, int>> m;
        for (int i=0; i!=g.size(); i++) if (g[i][0]=='O')
        {
            m.push({i, 0});
        }
        for (int i=0; i!=g.size(); i++) if (g[i][g[0].size()-1]=='O')
        {
            m.push({i, g[0].size()-1});
        }
        for (int j=0; j<g[0].size(); j++) if (g[0][j]=='O')
        {
            m.push({0, j});
        }
        for (int j=0; j<g[0].size(); j++) if (g[g.size()-1][j]=='O')
        {
            m.push({g.size()-1, j});
        }
        while (m.size()>0)
        {
            int x=m.top().first, y=m.top().second;
            m.pop();
            g[x][y]='A';
            if (x>0&&g[x-1][y]=='O')
            {
                m.push({x-1, y});
            }
            if (x<g.size()-1&&g[x+1][y]=='O')
            {
                m.push({x+1, y});
            }
            if (y>0&&g[x][y-1]=='O')
            {
                m.push({x, y-1});
            }
            if (y<g[0].size()-1&&g[x][y+1]=='O')
            {
                m.push({x, y+1});
            }
        }
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]=='A') g[i][j]='O';
                else if (g[i][j]=='O') g[i][j]='X';
            }
        }
    }
};