class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        int ans=1;
        while (n-4>0)
        {
            n-=3;
            ans*=3;
        }
        if (n==4) return ans*4;
        if (n==3) return ans*3;
        if (n==2) return ans*2;
        return ans;
    }
};