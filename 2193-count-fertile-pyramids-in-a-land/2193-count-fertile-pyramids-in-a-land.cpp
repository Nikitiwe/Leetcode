class Solution {
public:
    int countPyramids(vector<vector<int>>& g) {
        if (g.size()==1||g[0].size()<=2) return 0;
        vector<vector<int>> a=g;
        int ans=0;
        for (int k=1; k<min(g.size(), g[0].size()); k++)
        {
            for (int i=g.size()-1-k; i>=0; i--)
            {
                for (int j=k; j<g[0].size()-k; j++)
                {
                    if (g[i][j]>=k&&g[i+1][j-1]>=k&&g[i+1][j]>=k&&g[i+1][j+1]>=k)
                    {
                        g[i][j]=k+1;
                        ans++;
                    }
                }
            }
        }
        for (int k=1; k<min(g.size(), g[0].size()); k++)
        {
            for (int i=k; i<g.size(); i++)
            {
                for (int j=k; j<g[0].size()-k; j++)
                {
                    if (a[i][j]>=k&&a[i-1][j-1]>=k&&a[i-1][j]>=k&&a[i-1][j+1]>=k)
                    {
                        a[i][j]=k+1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};