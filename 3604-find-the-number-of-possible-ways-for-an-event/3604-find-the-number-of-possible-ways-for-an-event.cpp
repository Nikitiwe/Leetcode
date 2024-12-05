class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        long ans=0, mn=y;
        vector<vector<long>> arr(n, vector<long> (x, 0));
        arr[0][0]=x;
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<x; j++)
            {
                arr[i][j]=arr[i-1][j]*(j+1);
                if (j>0) arr[i][j]+=arr[i-1][j-1]*(x-j);
                arr[i][j]%=1000000007;
            }
        }
        for (int j=0; j<x; j++)
        {
            ans+=arr[n-1][j]*mn;
            mn*=y;
            ans%=1000000007;
            mn%=1000000007;
        }
        return ans;
    }
};