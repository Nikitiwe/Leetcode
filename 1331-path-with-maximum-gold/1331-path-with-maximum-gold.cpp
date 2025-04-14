class Solution {
public:
    void f(int &ans, vector<vector<int>> &t, int sum, int i, int j)
    {
        int add = t[i][j];
        sum += add;
        ans = max(ans, sum);
        t[i][j] = 0;
        if (i>0 && t[i-1][j] > 0) f(ans, t, sum, i-1, j);
        if (j>0 && t[i][j-1] > 0) f(ans, t, sum, i, j-1);
        if (i+1<t.size() && t[i+1][j] > 0) f(ans, t, sum, i+1, j);
        if (j+1<t[0].size() && t[i][j+1] > 0) f(ans, t, sum, i, j+1);
        t[i][j] = add;
    }

    int getMaximumGold(vector<vector<int>>& g) {
        int ans = 0;
        int n = g.size(), m = g[0].size();
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=m; j++)
            {
                if (g[i][j] > 0)
                {
                    int sum = 0;
                    f(ans, g, sum, i, j);
                }
            }
        }
        return ans;
    }
};