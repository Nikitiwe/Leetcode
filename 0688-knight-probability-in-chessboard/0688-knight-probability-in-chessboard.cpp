class Solution {
public:
    double knightProbability(int n, int kk, int r, int c) {
        vector<vector<double>> arr(n, vector<double> (n, 0)), next=arr, zero=arr;
        arr[r][c]=1;
        for (int k=1; k<=kk; k++)
        {
            for (int i=0; i!=n; i++)
            {
                for (int j=0; j!=n; j++)
                {
                    if (arr[i][j]>0)
                    {
                        if (i>=1&&j>=2) next[i-1][j-2]+=arr[i][j]/8;
                        if (i>=2&&j>=1) next[i-2][j-1]+=arr[i][j]/8;
                        if (i>=1&&j<=n-3) next[i-1][j+2]+=arr[i][j]/8;
                        if (i>=2&&j<=n-2) next[i-2][j+1]+=arr[i][j]/8;
                        if (i<=n-2&&j>=2) next[i+1][j-2]+=arr[i][j]/8;
                        if (i<=n-3&&j>=1) next[i+2][j-1]+=arr[i][j]/8;
                        if (i<=n-2&&j<=n-3) next[i+1][j+2]+=arr[i][j]/8;
                        if (i<=n-3&&j<=n-2) next[i+2][j+1]+=arr[i][j]/8;
                    }
                }
            }
            arr=next;
            next=zero;
        }
        double ans=0;
        for (int i=0; i!=n; i++) for (int j=0; j!=n; j++) ans+=arr[i][j];
        return ans;
    }
};