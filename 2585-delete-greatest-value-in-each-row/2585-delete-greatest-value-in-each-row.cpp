class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& g) {
        int ans=0;
        for (int k=0; k<g[0].size(); k++)
        {
            int t=0;
            for (int i=0; i!=g.size(); i++)
            {
                int id=0;
                for (int j=0; j!=g[0].size(); j++)
                {
                    if (g[i][j]>g[i][id]) id=j;
                }
                t=max(t, g[i][id]);
                g[i][id]=0;
            }
            ans+=t;
        }
        return ans;
    }
};