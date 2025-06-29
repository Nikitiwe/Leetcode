class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x > 0)
        {
            ans *= 10;
            ans += x % 10;
            x /=10;
        }
        if (x < 0)
        {
            while (x < 0)
            {
                ans *= 10;
                ans += x % 10;
                x /=10;
            }
        }
        if (ans <= INT_MAX && ans >= INT_MIN) return ans;
        else return 0;
    }
};