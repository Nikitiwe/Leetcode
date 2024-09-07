class Solution {
public:
    double myPow(double x, int nn) {
        if (nn==0) return 1;
        double ans=1, temp=1;
        long n=nn;
        if (n<0)
        {
            n*=-1;
            x=1/x;
        }
        if (n>0)
        {
            temp=x;
            //n--;
        }
        while (n>0)
        {
            if (n%2==0)
            {
                temp*=temp;
                n/=2;
            }
            else
            {
                ans*=temp;
                temp*=temp;
                n/=2;
            }
        }
        return ans;
    }
};