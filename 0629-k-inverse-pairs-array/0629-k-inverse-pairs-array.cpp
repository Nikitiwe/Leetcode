class Solution {
public:
    int kInversePairs(int n, int k) {
        long long mod = 1000000007;
        vector<vector<long long>> arr(n+1, vector<long long>(k+1, 0));
        arr[1][0] = 1;
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<=k; j++)
            {
                if (j > 0) arr[i][j] += arr[i][j-1];
                arr[i][j] %= mod;
                //if (i<n)
                {
                    arr[i+1][j] += arr[i][j];
                    if (j + i + 1 <= k) arr[i+1][j + i + 1] -= arr[i][j];
                }
            }
        }
        return (arr[n][k] + mod*mod) % mod;
    }
};