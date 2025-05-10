class Solution {
public:
    int minNonZeroProduct(int p) {
        long long ans = 1, mod = 1e9 + 7, mn = 1;
        for (int i=0; i<p; i++)
        {
            mn *= 2;
            //mn %= mod;
        }
        mn--;
        ans = mn;
        ans %= mod;
        mn--;
        long long t = mn/2;
        mn %= mod;
        /*for (int i=0; i<t; i++)
        {
            ans *= mn;
            ans %= mod;
        }*/
        while (t > 0)
        {
            if (t % 2 == 1)
            {
                ans *= mn;
                ans %= mod;
            }
            t /= 2;
            mn *= mn;
            mn %= mod;
        }
        return ans;
    }
};