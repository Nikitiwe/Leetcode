class Solution {
public:
    int totalMoney(int n) {
        int w=n/7;
        n%=7;
        return w*(49+w*7)/2+n*(1+2*w+n)/2;
    }
};