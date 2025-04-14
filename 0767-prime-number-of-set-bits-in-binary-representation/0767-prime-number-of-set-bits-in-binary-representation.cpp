class Solution {
public:
    bool f(int a)
    {
        int c = 0;
        while (a>0)
        {
            c += a%2;
            a /=2;
        }
        if ( c==2 || c==3 || c==5 || c==7 || c==11 || c==13 || c==17 || c==19 || c==23 || c==29 ) return 1;
        return 0;
    }

    int countPrimeSetBits(int a, int b) {
        int ans = 0;
        for (int i=a; i<=b; i++)
        {
            if (f(i) == 1) ans++;
        }
        return ans;
    }
};