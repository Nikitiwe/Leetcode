class Solution {
public:
    int projectionArea(vector<vector<int>>& g) {
        int ans=0;
        for (int i=0; i!=g.size(); i++)
        {
            int t=0;
            for (int j=0; j!=g[0].size(); j++)
            {
                t=max(t, g[i][j]);
            }
            ans+=t;
        }
        for (int j=0; j!=g[0].size(); j++)
        {
            int t=0;
            for (int i=0; i!=g.size(); i++)
            {
                t=max(t, g[i][j]);
            }
            ans+=t;
        }
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]>0) ans+=1;
            }
        }
        return ans;
    }
};