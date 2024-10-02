class Solution {
public:
    bool isPerfectSquare(int num) {
        long l=1, r=65535, m;
        while (l<r)
        {
            m=(l+r)/2;
            long t=m*m;
            if (t==num) return 1;
            else if (t<num) l=m+1;
            else r=m-1;
        }
        if (r*r==num) return 1;
        else return 0;
    }
};