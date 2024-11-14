class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& g) {
        for (int k=min(g.size(), g[0].size()); k>=1; k--)
        {
            for (int i=0; i<=g.size()-k; i++)
            {
                for (int j=0; j<=g[0].size()-k; j++)
                {
                    bool isit=1;
                    for (int a=0; a<k; a++)
                    {
                        if (g[i+a][j]==0)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1) for (int a=0; a<k; a++)
                    {
                        if (g[i][j+a]==0)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1) for (int a=0; a<k; a++)
                    {
                        if (g[i+a][j+k-1]==0)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1) for (int a=0; a<k; a++)
                    {
                        if (g[i+k-1][j+a]==0)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==1)
                    {
                        return k*k;
                    }
                }
            }
        }
        return 0;
    }
};