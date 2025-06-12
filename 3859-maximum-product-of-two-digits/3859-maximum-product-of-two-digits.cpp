class Solution {
public:
    int maxProduct(int n) {
        int a = -1, b = -1;
        while (n > 0)
        {
            int t = n % 10;
            if (t >= a)
            {
                b = a;
                a = t;
            }
            else if (t >= b) b = t;
            n /= 10;
        }
        return a*b;
    }
};