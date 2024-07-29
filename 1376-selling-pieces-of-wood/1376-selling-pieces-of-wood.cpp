class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> pr;
        vector<long long> row(n+1, 0);
        for (int i=0; i<=m; i++) pr.push_back(row);
        for (int k=0; k<prices.size(); k++)
        {
            pr[prices[k][0]][prices[k][1]]=prices[k][2];
        }
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                for (int k=1; k<=i/2; k++)
                {
                    pr[i][j]=max(pr[i][j], pr[k][j]+pr[i-k][j]);
                }
                for (int k=1; k<=j/2; k++)
                {
                    pr[i][j]=max(pr[i][j], pr[i][k]+pr[i][j-k]);
                }
            }
        }
        return pr[m][n];
    }
};