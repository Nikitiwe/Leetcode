class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int t = 1, add = 0;
        for (int i=1; i<=n; i++)
        {
            ans[i] = ans[i - t] + 1;
            add++;
            if (add == t)
            {
                t*=2;
                add = 0;
            }
        }
        return ans;
    }
};