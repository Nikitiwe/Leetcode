class Solution {
public:
    int countWinningSequences(string s) {
        long mod = 1e9 + 7;
        int n = s.size();
        vector<vector<long>> f(n, vector<long>(n*2 + 3, 0)), e = f, w = f;
        // n это 0 очков, f[i][j] это число способов иметь j очков после i символа сыграв f
        if (s[0] == 'F')
        {
            f[0][n+1] = 1;
            e[0][n] = 1;
            w[0][n+2] = 1;
        }
        else if (s[0] == 'W')
        {
            w[0][n+1] = 1;
            f[0][n] = 1;
            e[0][n+2] = 1;
        }
        else if (s[0] == 'E')
        {
            e[0][n+1] = 1;
            w[0][n] = 1;
            f[0][n+2] = 1;
        }
        for (int i=1; i<n; i++)
        {
            if (s[i] == 'F') for (int j=n-i; j<=n+i+2; j++)
            {
                f[i][j] += e[i-1][j];
                f[i][j] += w[i-1][j];
                f[i][j] %= mod;

                e[i][j] += f[i-1][j+1];
                e[i][j] += w[i-1][j+1];
                e[i][j] %= mod;

                w[i][j] += f[i-1][j-1];
                w[i][j] += e[i-1][j-1];
                w[i][j] %= mod;
            }
            else if (s[i] == 'E') for (int j=n-i; j<=n+i+2; j++)
            {
                f[i][j] += e[i-1][j-1];
                f[i][j] += w[i-1][j-1];
                f[i][j] %= mod;

                e[i][j] += f[i-1][j];
                e[i][j] += w[i-1][j];
                e[i][j] %= mod;

                w[i][j] += f[i-1][j+1];
                w[i][j] += e[i-1][j+1];
                w[i][j] %= mod;
            }
            else if (s[i] == 'W') for (int j=n-i; j<=n+i+2; j++)
            {
                f[i][j] += e[i-1][j+1];
                f[i][j] += w[i-1][j+1];
                f[i][j] %= mod;

                e[i][j] += f[i-1][j-1];
                e[i][j] += w[i-1][j-1];
                e[i][j] %= mod;

                w[i][j] += f[i-1][j];
                w[i][j] += e[i-1][j];
                w[i][j] %= mod;
            }
        }
        long ans = 0;
        for (int i=n+2; i<n*2+3; i++)
        {
            ans += f[n-1][i];
            ans += w[n-1][i];
            ans += e[n-1][i];
            ans %= mod;
        }
        return ans;
    }
};