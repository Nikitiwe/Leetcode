class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& e) {
        long long ans = (long long)n*(n-1);
        for (long long i = n; i>2; i--)
        {
            ans += i*(i-2);
        }
        if (e.size() == n) ans += 2;
        return ans;
    }
};