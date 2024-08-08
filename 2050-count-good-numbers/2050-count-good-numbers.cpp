class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans=1;
        while (n>10000000000)
        {
            ans*=176203868;
            ans%=1000000007;
            n-=10000000000;
        }
        while (n>100000)
        {
            ans*=86331955;
            ans%=1000000007;
            n-=100000;
        }
        for (int i=0; i!=n; i++)
        {
            if (i%2==0) ans*=5;
            else ans*=4;
            ans%=1000000007;
        }
        return ans;
    }
};