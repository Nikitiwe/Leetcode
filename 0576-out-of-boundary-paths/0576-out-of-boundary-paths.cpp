class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove==0) return 0;
        vector<vector<long long>> prev, next, zero;
        vector<long long> row(n, 0);
        for (int i=0; i!=m; i++) prev.push_back(row);
        next=prev;
        zero=prev;
        long long ans=0;
        prev[startRow][startColumn]=1;
        for (int k=1; k<maxMove; k++)
        {
            for (int i=0; i!=m; i++) ans+=prev[i][0]+prev[i][n-1];
            for (int j=0; j!=n; j++) ans+=prev[0][j]+prev[m-1][j];
            ans%=1000000007;
            for (int i=0; i!=m; i++)
            {
                for (int j=0; j!=n; j++)
                {
                    if (i>0) next[i][j]+=prev[i-1][j];
                    if (j>0) next[i][j]+=prev[i][j-1];
                    if (i<m-1) next[i][j]+=prev[i+1][j];
                    if (j<n-1) next[i][j]+=prev[i][j+1];
                    next[i][j]%=1000000007;
                }
            }
            prev=next;
            next=zero;
        }
        for (int i=0; i!=m; i++) ans+=prev[i][0]+prev[i][n-1];
        for (int j=0; j!=n; j++) ans+=prev[0][j]+prev[m-1][j];
        return ans%1000000007;
    }
};