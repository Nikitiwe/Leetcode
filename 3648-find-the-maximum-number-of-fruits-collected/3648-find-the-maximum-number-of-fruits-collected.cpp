class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& g) {
        int ans=0, n=g.size();
        if (n==2) return g[n-2][n-2]+g[n-1][n-1]+g[n-2][n-1]+g[n-1][n-2];
        if (n==3) return g[n-3][n-3]+g[n-1][n-3]+g[n-3][n-1]+g[n-2][n-2]+g[n-1][n-1]+g[n-2][n-1]+g[n-1][n-2];
        for (int i=0; i!=n; i++) ans+=g[i][i];
        if (n%2==0)
        {
        for (int i=1; i<n; i++)
        {
            int j=0;
            if (i<n/2) for (j=n-1-i; j<n; j++)
            {
                int t=0;
                if (j<n-1) t=g[i-1][j+1];
                if (j+i>=n) t=max(g[i-1][j], t);
                if (j+i>=n+1) t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
            if (i>=n/2) for (j=i+1; j<n; j++)
            {
                int t=0;
                if (j<n-1) t=g[i-1][j+1];
                t=max(g[i-1][j], t);
                t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
        }
        for (int j=1; j<n; j++)
        {
            int i=0;
            if (j<n/2) for (i=n-1-j; i<n; i++)
            {
                int t=0;
                if (i<n-1) t=g[i+1][j-1];
                if (j+i>=n) t=max(g[i][j-1], t);
                if (j+i>=n+1) t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
            if (j>=n/2) for (i=j+1; i<n; i++)
            {
                int t=0;
                if (i<n-1) t=g[i+1][j-1];
                t=max(g[i][j-1], t);
                t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
        }
        }
        else
        {
        for (int i=1; i<n; i++)
        {
            int j=0;
            if (i<=n/2) for (j=n-1-i; j<n; j++)
            {
                int t=0;
                if (j<n-1) t=g[i-1][j+1];
                if (j+i>=n) t=max(g[i-1][j], t);
                if (j+i>=n+1) t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
            if (i>n/2) for (j=i+1; j<n; j++)
            {
                int t=0;
                if (j<n-1) t=g[i-1][j+1];
                t=max(g[i-1][j], t);
                t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
        }
        for (int j=1; j<n; j++)
        {
            int i=0;
            if (j<=n/2) for (i=n-1-j; i<n; i++)
            {
                int t=0;
                if (i<n-1) t=g[i+1][j-1];
                if (j+i>=n) t=max(g[i][j-1], t);
                if (j+i>=n+1) t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
            if (j>n/2) for (i=j+1; i<n; i++)
            {
                int t=0;
                if (i<n-1) t=g[i+1][j-1];
                t=max(g[i][j-1], t);
                t=max(g[i-1][j-1], t);
                g[i][j]+=t;
            }
        }
        }
        return ans+g[n-2][n-1]+g[n-1][n-2];
    }
};