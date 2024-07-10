class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans=1;
        if (m<n) swap (m, n);
        for (int i=1; i<=n-1; i++)
        {
            ans=ans*(m-1+i)/i;
        }
        return ans;
    }
};