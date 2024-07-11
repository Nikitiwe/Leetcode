class Solution {
public:
    int mirrorReflection(int p, int q) {
        int a=gcd(p, q);
        p=p/a;
        q=q/a;
        if (q%2==1&&p%2==1) return 1;
        else if (q%2==0&&p%2==1) return 0;
        else return 2;
    }
};