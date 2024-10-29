class Solution {
public:
    int numOfWays(int n) {
        vector<vector<long>> ans(n, vector<long> (12, 0));
        for (int j=0; j!=12; j++) ans[0][j]=1;
        for (int i=1; i<n; i++)
        {
            ans[i][0]=(ans[i-1][4]+ans[i-1][5]+ans[i-1][7]+ans[i-1][8]+ans[i-1][9])%1000000007;
            ans[i][1]=(ans[i-1][4]+ans[i-1][6]+ans[i-1][7]+ans[i-1][8])%1000000007;
            ans[i][2]=(ans[i-1][4]+ans[i-1][5]+ans[i-1][8]+ans[i-1][9]+ans[i-1][11])%1000000007;
            ans[i][3]=(ans[i-1][5]+ans[i-1][9]+ans[i-1][10]+ans[i-1][11])%1000000007;
            ans[i][4]=(ans[i-1][0]+ans[i-1][1]+ans[i-1][2]+ans[i-1][10]+ans[i-1][11])%1000000007;
            ans[i][5]=(ans[i-1][0]+ans[i-1][2]+ans[i-1][3]+ans[i-1][10])%1000000007;
            ans[i][6]=(ans[i-1][1]+ans[i-1][8]+ans[i-1][9]+ans[i-1][11])%1000000007;
            ans[i][7]=(ans[i-1][0]+ans[i-1][1]+ans[i-1][9]+ans[i-1][10]+ans[i-1][11])%1000000007;
            ans[i][8]=(ans[i-1][0]+ans[i-1][1]+ans[i-1][2]+ans[i-1][6])%1000000007;
            ans[i][9]=(ans[i-1][0]+ans[i-1][2]+ans[i-1][3]+ans[i-1][6]+ans[i-1][7])%1000000007;
            ans[i][10]=(ans[i-1][3]+ans[i-1][4]+ans[i-1][5]+ans[i-1][7])%1000000007;
            ans[i][11]=(ans[i-1][2]+ans[i-1][3]+ans[i-1][4]+ans[i-1][6]+ans[i-1][7])%1000000007;

            /*for (int j=0; j!=12; j++)
            {
                ans[i][j]%=1000000007;
            }*/
        }
        long t=0;
        for (int j=0; j!=12; j++) t+=ans[n-1][j];
        return t%1000000007;
    }
};