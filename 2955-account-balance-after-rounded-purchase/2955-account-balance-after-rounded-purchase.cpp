class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        if (p%10<=4) return 100-p+p%10;
        else return 90-p+p%10;
    }
};