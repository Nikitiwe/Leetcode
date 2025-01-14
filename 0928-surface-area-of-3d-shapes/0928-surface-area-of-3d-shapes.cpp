class Solution {
public:
    int surfaceArea(vector<vector<int>>& g) {
        int ans=0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]>0)
                {
                    ans+=1;
                    int t=1;
                    while (t<=g[i][j])
                    {
                        /*if (i==0) ans+=1;
                        if (j==0) ans+=1;*/

                        if (i>0&&g[i-1][j]>=t) ans+=0;
                        else ans+=1;
                        if (j>0&&g[i][j-1]>=t) ans+=0;
                        else ans+=1;

                        if (i<g.size()-1&&g[i+1][j]>=t) ans+=0;
                        else ans+=1;
                        if (j<g[0].size()-1&&g[i][j+1]>=t) ans+=0;
                        else ans+=1;

                        /*if (i==g.size()-1) ans+=1;
                        if (j==g[0].size()-1) ans+=1;*/
                        t++;
                    }
                    ans+=1;
                }
            }
        }
        return ans;
    }
};