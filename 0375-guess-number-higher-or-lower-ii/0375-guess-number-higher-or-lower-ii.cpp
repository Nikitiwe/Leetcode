unordered_map<int, int> m;

class Solution {
public:
    int f(int l, int r)
    {
        if (l >= r) return 0;
        if (l + 1 == r) return l;
        if (m.count(1000*l + r) == 0)
        {
            int ans = 100000000;
            for (int i=l; i<=r; i++)
            {
                ans = min(ans, i + max(f(l, i-1), f(i+1, r)) );
            }
            m[1000*l + r] = ans;
        }
        return m[1000*l + r];
    }

    int getMoneyAmount(int n) {
        return f(1, n);
    }
};