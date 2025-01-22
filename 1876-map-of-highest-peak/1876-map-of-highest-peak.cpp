class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) {
        vector<vector<int>> ans(g.size(), vector<int> (g[0].size(), 2000));
        queue<vector<int>> m;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]==1)
                {
                    m.push({i, j, 0});
                    ans[i][j]=0;
                }
            }
        }
        while (m.size()>0)
        {
            int x=m.front()[0], y=m.front()[1], h=m.front()[2];
            if (ans[x][y]>=h)
            {
                ans[x][y]=h;
                if (x>0&&ans[x-1][y]>h+1)
                {
                    m.push({x-1, y, h+1});
                    ans[x-1][y]=h+1;
                }
                if (x<g.size()-1&&ans[x+1][y]>h+1)
                {
                    m.push({x+1, y, h+1});
                    ans[x+1][y]=h+1;
                }
                if (y>0&&ans[x][y-1]>h+1)
                {
                    m.push({x, y-1, h+1});
                    ans[x][y-1]=h+1;
                }
                if (y<g[0].size()-1&&ans[x][y+1]>h+1)
                {
                    m.push({x, y+1, h+1});
                    ans[x][y+1]=h+1;
                }
            }
            m.pop();
        }
        return ans;
    }
};