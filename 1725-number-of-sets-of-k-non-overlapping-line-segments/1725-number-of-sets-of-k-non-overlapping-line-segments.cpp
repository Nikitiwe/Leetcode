class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<int> prev(n, 0), next(n, 0), zero(n, 0);
        for (int i=0; i!=n; i++) prev[i]=i;
        for (int i=2; i<=k; i++)
        {
            int s=0;
            for (int j=i; j<n; j++)
            {
                s+=prev[j-1];
                s%=1000000007;
                next[j]+=s;
                next[j]+=next[j-1];
                next[j]%=1000000007;
            }
            prev=next;
            next=zero;
        }
        int ans=0;
        for (int i=0; i!=n; i++)
        {
            ans+=prev[i];
            ans%=1000000007;
        }
        return ans;
    }
};