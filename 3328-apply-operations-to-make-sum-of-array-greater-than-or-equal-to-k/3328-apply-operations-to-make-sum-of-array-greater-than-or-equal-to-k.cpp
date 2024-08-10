class Solution {
public:
    int minOperations(int k) {
        int t=sqrt(k);
        if (t*t<k) t++;
        if (t*(t-1)>=k) return 2*t-3;
        else return 2*t-2;
    }
};