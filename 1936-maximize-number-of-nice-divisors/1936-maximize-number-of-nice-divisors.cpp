class Solution {
public:
    int maxNiceDivisors(int k) {
        long long ans = 1, mod = 1e9 + 7;
        while (k > 1000003)
        {
            ans *= 154951791;
            ans %= mod;
            k -= 999999;
        }
        while (k > 1002)
        {
            ans *= 965709895;
            ans %= mod;
            k -= 999;
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