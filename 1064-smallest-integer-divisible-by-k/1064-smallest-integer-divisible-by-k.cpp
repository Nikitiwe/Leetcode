class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k==1) return 1;
        int a=1;
        for (int i=1; i<=k; i++)
        {
            if (a==0) return i;
            a*=10;
            a++;
            a%=k;
        }
        return -1;
    }
};