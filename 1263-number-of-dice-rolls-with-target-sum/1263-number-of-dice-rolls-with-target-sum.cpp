class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> ans(1001, 0), prew(1001, 0);
        for (int i=0; i!=k; i++)
        { prew[i+1]=1; }
        long long temp;
        for (int i=1; i!=n; i++)
        {
            for (int j=1; j<=min(1000, (i+1)*k); j++)
            {
                temp=0;
                for (int t=j-1; t>0&&t>=j-k; t--)
                {
                    temp+=prew[t];
                }
                temp=temp%1000000007;
                ans[j]=temp;
            }
            prew=ans;
        }
        return prew[target];
    }
};