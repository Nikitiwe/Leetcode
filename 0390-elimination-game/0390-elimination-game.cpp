class Solution {
public:
    int lastRemaining(int n) {
        int d = 1, r = 1, a = 0;
        while (n>1)
        {
            if (a%2==0)
            {
                r += d;
            }
            else
            {
                if (n % 2 == 1) r += d;
            }
            d *= 2;
            n /= 2;
            a++;
        }
        return r;
    }
};