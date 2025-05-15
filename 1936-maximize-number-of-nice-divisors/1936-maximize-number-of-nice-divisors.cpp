class Solution {
public:
    int maxNiceDivisors(int k) {
        long ans = 1, mod = 1e9 + 7;
        while (k > 30000)
        {
            ans *= 895629451;
            ans %= mod;
            k -= 30000;
        }
        while (k > 4)
        {
            ans *= 3;
            ans %= mod;
            k -= 3;
        }
        ans *= k;
        ans %= mod;
        return ans;
    }
};