class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int d=gcd(a, b), count=0, t, c;
        long long ans=0, ta=0, tb=0, ab;
        t=a+b-d;
        c=n%t;
        ab=a*b%1000000007;
        ans=(n/t)*ab%1000000007;
        if (a>b) swap(a,b);
        while (count!=c)
        {
            if (min(ta+a, tb+b)==tb+b) {tb=tb+b; if (ta!=tb) count++;}
            else {ta=ta+a; if (ta!=tb) count++;}
        }
        if (n==1) return a;
        else return (ans+max(ta, tb))%1000000007;
    }
};