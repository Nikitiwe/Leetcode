class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int ans=1;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                for (int k=ans; i+k<g.size()&&j+k<g[0].size(); k++)
                {
                    int s=0;
                    for (int a=0; a<=k; a++) s+=g[i+a][j+a];
                    bool isit=1;
                    for (int a=0; a<=k; a++)
                    {
                        int t=0;
                        for (int b=0; b<=k; b++)
                        {
                            t+=g[i+a][j+b];
                        }
                        if (t!=s)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1) for (int a=0; a<=k; a++)
                    {
                        int t=0;
                        for (int b=0; b<=k; b++)
                        {
                            t+=g[i+b][j+a];
                        }
                        if (t!=s)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1)
                    {
                        int t=0;
                        for (int a=0; a<=k; a++) t+=g[i+a][j+k-a];
                        if (t!=s)
                        {
                            isit=0;
                        }
                    }
                    if (isit==1) ans=max(ans, k+1);
                }
            }
        }
        return ans;
    }
};