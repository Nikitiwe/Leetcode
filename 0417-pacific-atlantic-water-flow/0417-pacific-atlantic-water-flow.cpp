class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& g) {
        vector<vector<int>> ans (g.size(), vector<int> (g[0].size(), 0));
        queue<pair<int, int>> m;
        for (int i=0; i!=g.size(); i++)
        {
            m.push({i, 0});
            ans[i][0]=1;
        }
        for (int j=1; j<g[0].size(); j++)
        {
            m.push({0, j});
            ans[0][j]=1;
        }
        while (m.size()>0)
        {
            int x=m.front().first, y=m.front().second, h=g[x][y];
            if (x>0&&ans[x-1][y]==0&&g[x-1][y]>=h)
            {
                ans[x-1][y]=1;
                m.push({x-1, y});
            }
            if (y>0&&ans[x][y-1]==0&&g[x][y-1]>=h)
            {
                ans[x][y-1]=1;
                m.push({x, y-1});
            }
            if (x+1<g.size()&&ans[x+1][y]==0&&g[x+1][y]>=h)
            {
                ans[x+1][y]=1;
                m.push({x+1, y});
            }
            if (y+1<g[0].size()&&ans[x][y+1]==0&&g[x][y+1]>=h)
            {
                ans[x][y+1]=1;
                m.push({x, y+1});
            }
            m.pop();
        }
        for (int i=0; i!=g.size(); i++)
        {
            m.push({i, g[0].size()-1});
            ans[i][g[0].size()-1]+=2;
        }
        for (int j=0; j<g[0].size()-1; j++)
        {
            m.push({g.size()-1, j});
            ans[g.size()-1][j]+=2;
        }
        while (m.size()>0)
        {
            int x=m.front().first, y=m.front().second, h=g[x][y];
            if (x>0&&ans[x-1][y]<2&&g[x-1][y]>=h)
            {
                ans[x-1][y]+=2;
                m.push({x-1, y});
            }
            if (y>0&&ans[x][y-1]<2&&g[x][y-1]>=h)
            {
                ans[x][y-1]+=2;
                m.push({x, y-1});
            }
            if (x+1<g.size()&&ans[x+1][y]<2&&g[x+1][y]>=h)
            {
                ans[x+1][y]+=2;
                m.push({x+1, y});
            }
            if (y+1<g[0].size()&&ans[x][y+1]<2&&g[x][y+1]>=h)
            {
                ans[x][y+1]+=2;
                m.push({x, y+1});
            }
            m.pop();
        }
        vector<vector<int>> res;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (ans[i][j]==3) res.push_back({i, j});
            }
        }
        return res;
    }
};