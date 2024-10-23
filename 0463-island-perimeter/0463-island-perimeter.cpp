class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int ans=0;
        for (int i=1; i<g.size(); i++)
        {
            for (int j=1; j<g[0].size(); j++)
            {
                if (g[i][j]==1)
                {
                    if (g[i-1][j]==0) ans++;
                    if (g[i][j-1]==0) ans++;
                }
            }
        }
        for (int i=1; i<g.size(); i++)
        {
            if (g[i][0]==1)
            {
                if (g[i-1][0]==0) ans++;
                ans++;
            }
        }
        for (int j=1; j<g[0].size(); j++)
        {
            if (g[0][j]==1)
            {
                ans++;
                if (g[0][j-1]==0) ans++;
            }
        }
        if (g[0][0]) ans+=2;
        return ans*2;
    }
};