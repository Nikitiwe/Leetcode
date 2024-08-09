class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> arr(n, 0);
        arr[0]=1;
        long mod=1000000007, ans=0;
        for (int i=1; i<n; i++)
        {
            if (i>=forget) arr[i-forget]=0;
            if (i>=delay)
            {
                for (int j=0; j<=i-delay; j++) arr[i]+=arr[j];
                arr[i]%=mod;
            }
        }
        for (int i=0; i<n; i++)
        {
            ans+=arr[i];
            ans%=mod;
        }
        return ans;
    }
};