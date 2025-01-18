class Solution {
public:
    int hammingWeight(int n) {
        int t=0;
        while (n>0)
        {
            t+=n%2;
            n/=2;
        }
        return t;
    }
};