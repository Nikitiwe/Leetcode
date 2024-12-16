class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
        vector<int> l(g.size()*g[0].size(), 0), r=l;
        int mod=12345;
        g[0][0]%=mod;
        int p=g[0][0];
        l[0]=p;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
               if (i!=0||j!=0)
               {
                    g[i][j]%=mod;
                    p*=g[i][j];
                    p%=mod;
                    l[i*g[0].size()+j]=p;
               }
            }
        }
        p=g[g.size()-1][g[0].size()-1];
        p%=mod;
        r.back()=p;
        for (int i=g.size()-1; i>=0; i--)
        {
            for (int j=g[0].size()-1; j>=0; j--)
            {
               if (i!=g.size()-1||j!=g[0].size()-1)
               {
                    p*=g[i][j];
                    p%=mod;
                    r[i*g[0].size()+j]=p;
               }
            }
        }
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if ((i!=0||j!=0)&&(i!=g.size()-1||j!=g[0].size()-1))
                {
                    g[i][j]=l[i*g[0].size()+j-1]*r[i*g[0].size()+j+1];
                    g[i][j]%=mod;
                }
            }
        }
        g[0][0]=r[1];
        g[0][0]%=mod;
        g[g.size()-1][g[0].size()-1]=l[l.size()-2];
        g[g.size()-1][g[0].size()-1]%=mod;
        return g;
    }
};