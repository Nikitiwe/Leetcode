class Solution {
public:
    int colorTheGrid(int mm, int n) {
        long long mod = 1e9 + 7;
        int m = 3;
        for (int i = 1; i<mm; i++) m *= 3;
        vector<vector<long long>> arr(n, vector<long long>(m, 0));
        vector<bool> isit(m, 0);
        vector<vector<int>> c(m, vector<int>(mm, 0));
        for (int j=0; j!=m; j++)
        {
            int t = j;
            vector<int> a(mm, 0);
            for (int k=0; k < mm; k++)
            {
                a[k] = t % 3;
                t /= 3;
            }
            bool isd = 1;
            for (int k=0; k+1 < mm; k++) if (a[k] == a[k+1]) {isd = 0; break;}
            if (isd == 1)
            {
                arr[0][j] = 1;
                isit[j] = 1;
                c[j] = a;
            }
        }
        for (int i=1; i!=n; i++)
        {
            for (int j=0; j!=m; j++)
            {
                if (isit[j] == 1) for (int l=0; l!=m; l++)
                {
                    bool isdd = isit[l];
                    if (isdd == 1) for (int k=0; k < mm; k++) if (c[j][k] == c[l][k]) {isdd = 0; break;}
                    if (isdd == 1)
                    {
                        arr[i][l] += arr[i-1][j];
                        arr[i][l] %= mod;
                    }
                }
            }
        }
        long long ans = 0;
        for (int j=0; j!=m; j++) ans += arr[n-1][j];
        return ans % mod;
    }
};