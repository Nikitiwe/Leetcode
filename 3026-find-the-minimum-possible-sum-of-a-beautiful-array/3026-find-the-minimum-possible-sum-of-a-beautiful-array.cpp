class Solution {
public:
    int minimumPossibleSum(int nn, int tt) {
        long ans=0, t=tt, n=nn;
        if (n+n-1<t) return (n*(n+1)/2)%1000000007;
        if (n==1) return 1;
        ans+=(t/2)*(t/2+1)/2+(n-t/2)*(t+t+n-t/2-1)/2;
        return ans%1000000007;
    }
};