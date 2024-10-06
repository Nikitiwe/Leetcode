class Solution {
public:
    int arrangeCoins(int n) {
        long ans=(sqrt(1+8*(long)n)-1)/2;
        return ans;
    }
};