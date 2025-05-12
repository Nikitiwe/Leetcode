class Solution {
public:
    unordered_map<int, int> m;

    int minDays(int n) {
        if (n == 1) return 1;
        if (n == 0) return 0;
        if (m.count(n) == 0)
        {
            int ans = 70;
            if (n % 2 == 0) ans = min(ans, minDays(n/2));
            else ans = min(ans, 1 + minDays(n/2));
            if (n % 3 == 0) ans = min(ans, minDays(n/3));
            else if (n % 3 == 1) ans = min(ans, 1 + minDays(n/3));
            else ans = min(ans, 2 + minDays(n/3));
            m[n] = 1 + ans;
        }
        return m[n];
    }
};