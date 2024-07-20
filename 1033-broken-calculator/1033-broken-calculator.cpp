class Solution {
public:
    int brokenCalc(int startValue, int target) {
        long s=startValue, t=target, a=1;
        if (s>=t) return s-t;
        int ans=0;
        while (s<t)
        {
            s*=2;
            a*=2;
            ans++;
        }
        s-=t;
        while (s>0)
        {
            if (s-a>=0) {s-=a; ans++; if (s==0) break;}
            else a/=2;
        }
        return ans;
    }
};