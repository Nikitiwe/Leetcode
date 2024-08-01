class Solution {
public:
    int smallestValue(int n) {
        int m=0, temp=n, d=2;
        while (1) {
        while (n>1)
        {
            if (n%d==0) {m+=d; n/=d;}
            else d++;
        }
        if (m==temp) return m;
        else {n=m; m=0; temp=n; d=2;}
        }
        return 0;
    }
};