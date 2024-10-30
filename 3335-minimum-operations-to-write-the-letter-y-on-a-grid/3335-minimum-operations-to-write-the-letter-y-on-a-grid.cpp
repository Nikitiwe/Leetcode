class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& g) {
        int ans=10000000, t;
        for (int k=0; k!=3; k++)
        {
            for (int a=0; a!=3; a++)
            {
            if (k!=a)
            {
            t=0;
            for (int i=0; i!=g.size()/2; i++)
            {
                for (int j=0; j!=g[0].size(); j++)
                {
                    if (i==j||g.size()-1-i==j)
                    {
                        if (g[i][j]!=k) t++;
                    }
                    else if (g[i][j]!=a) t++;
                }
            }
            for (int i=g.size()/2; i!=g.size(); i++)
            {
                for (int j=0; j!=g[0].size(); j++)
                {
                    if (j==g[0].size()/2)
                    {
                        if (g[i][j]!=k) t++;
                    }
                    else if (g[i][j]!=a) t++;
                }
            }
            ans=min(ans, t);
            }
            }
        }
        return ans;
    }
};