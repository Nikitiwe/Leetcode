class Solution {
public:
    int countPalindromes(string s) {
        int n=s.size();
        if (n<5) return 0;
        vector<vector<long>> l1(n, vector<long> (10, 0)), r1(n, vector<long> (10, 0));
        vector<vector<long>> l2(n, vector<long> (100, 0)), r2(n, vector<long> (100, 0));
        l1[1][s[0]-'0']++;
        for (int i=2; i<n; i++)
        {
            l1[i][s[i-1]-'0']++;
            for (int j=0; j!=10; j++) l1[i][j]+=l1[i-1][j];
        }
        for (int i=2; i<n; i++)
        {
            for (int j=0; j!=10; j++)
            {
                l2[i][(s[i-1]-'0')+10*j]+=l1[i-1][j];
            }
            for (int j=0; j!=100; j++)
            {
                l2[i][j]+=l2[i-1][j];
                l2[i][j]%=1000000007;
            }
        }
        r1[n-2][s[n-1]-'0']++;
        for (int i=n-3; i>=0; i--)
        {
            r1[i][s[i+1]-'0']++;
            for (int j=0; j!=10; j++) r1[i][j]+=r1[i+1][j];
        }
        for (int i=n-3; i>=0; i--)
        {
            for (int j=0; j!=10; j++)
            {
                r2[i][(s[i+1]-'0')+10*j]+=r1[i+1][j];
            }
            for (int j=0; j!=100; j++)
            {
                r2[i][j]+=r2[i+1][j];
                r2[i][j]%=1000000007;
            }
        }
        long ans=0;
        for (int i=2; i<n-2; i++)
        {
            for (int j=0; j!=100; j++)
            {
                ans+=l2[i][j]*r2[i][j];
            }
            ans%=1000000007;
        }
        return ans;
    }
};