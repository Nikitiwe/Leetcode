class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        if (k <= numOnes) return k;
        else
        {
            k -= numOnes;
            ans += numOnes;
        }
        if (k <= numZeros) return ans;
        else
        {
            k -= numZeros;
        }
        return ans - k;
    }
};