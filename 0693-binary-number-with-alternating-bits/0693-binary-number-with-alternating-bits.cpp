class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p = n%2;
        n /= 2;
        while (n > 0)
        {
            if ( p == n%2) return 0;
            n /= 2;
            p = 1 - p;
        }
        return 1;
    }
};