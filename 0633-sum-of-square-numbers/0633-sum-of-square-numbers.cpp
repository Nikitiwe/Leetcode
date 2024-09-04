class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c%4==3) return 0;
        int cc=sqrt(c), t, a;
        for (int i=0; i<=cc; i++)
        {
            t=c-i*i;
            a=sqrt(t);
            if (a*a==t) return 1;
        }
        return 0;
    }
};