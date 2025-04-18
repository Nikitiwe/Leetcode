/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& f, int z) {
        vector<vector<int>> res;
        int ll = 1, rr = 1000;
        for (int i=1; i<=1000; i++)
        {
            int l = 1, r = rr, m;
            if (f.f(i, l) > z) break;
            int ans = 5000;
            while (l <= r)
            {
                m = (l+r)/2;
                if (f.f(i, m) >= z)
                {
                    ans = min(ans, m);
                    r = m-1;
                }
                else l = m+1;
            }
            if (f.f(i, ans) == z) res.push_back({i, ans});
            rr = l;
        }
        return res;
    }
};