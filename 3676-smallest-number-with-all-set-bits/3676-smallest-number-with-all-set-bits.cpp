class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1, d = 2;
        while (ans < n)
        {
            ans += d;
            d *= 2;
        }
        return ans;
    }
};