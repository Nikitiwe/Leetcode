class Solution {
public:
    int maxProductPath(vector<vector<int>>& g) {
        vector<vector<long long>> p(g.size(), vector<long long> (g[0].size(), -1)), n(g.size(), vector<long long> (g[0].size(), 1));
        p[0][0]=g[0][0];
        n[0][0]=g[0][0];
        for (int i=0; i!=g.size(); i++)
        {
            if (i==0) for (int j=1; j<g[0].size(); j++)
            {
                p[i][j]=p[i][j-1]*g[i][j];
                p[i][j]=max(n[i][j-1]*g[i][j], p[i][j]);
                //p[i][j]%=1000000007;
                n[i][j]=n[i][j-1]*g[i][j];
                n[i][j]=min(p[i][j-1]*g[i][j], n[i][j]);
                //n[i][j]%=1000000007;
            }
            else for (int j=0; j!=g[0].size(); j++)
            {
                p[i][j]=p[i-1][j]*g[i][j];
                if (j>0) p[i][j]=max(p[i][j-1]*g[i][j], p[i][j]);
                p[i][j]=max(n[i-1][j]*g[i][j], p[i][j]);
                if (j>0) p[i][j]=max(n[i][j-1]*g[i][j], p[i][j]);
                //p[i][j]%=1000000007;
                n[i][j]=n[i-1][j]*g[i][j];
                n[i][j]=min(p[i-1][j]*g[i][j], n[i][j]);
                if (j>0) n[i][j]=min(n[i][j-1]*g[i][j], n[i][j]);
                if (j>0) n[i][j]=min(p[i][j-1]*g[i][j], n[i][j]);
                //n[i][j]%=1000000007;
            }
        }
        if (p[g.size()-1][g[0].size()-1]>=0) return p[g.size()-1][g[0].size()-1]%1000000007;
        else return -1;
    }
};