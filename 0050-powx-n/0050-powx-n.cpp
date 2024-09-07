class Solution {
public:
    double myPow(double x, int nn) {
        double ans=1, temp=1;
        long n=nn;
        int m=10000;
        if (n==0) return ans;
        if (n<0)
        {
            n*=-1;
            x=1/x;
        }
        if (n>10000) while (m>0)
        {
            temp*=x;
            m--;
        }
        while (n>10000)
        {
            ans*=temp;
            n-=10000;
        }
        while (n>0)
        {
            ans*=x;
            n--;
        }
        return ans;
    }
};