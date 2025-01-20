class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int ans=0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]=='1')
                {
                    ans++;
                    stack<pair<int, int>> m;
                    m.push({i, j});
                    while (m.size()>0)
                    {
                        int x=m.top().first, y=m.top().second;
                        m.pop();
                        g[x][y]='2';
                        if (x>0&&g[x-1][y]=='1') m.push({x-1, y});
                        if (x<g.size()-1&&g[x+1][y]=='1') m.push({x+1, y});
                        if (y>0&&g[x][y-1]=='1') m.push({x, y-1});
                        if (y<g[0].size()-1&&g[x][y+1]=='1') m.push({x, y+1});
                    }
                }
            }
        }
        return ans;
    }
};