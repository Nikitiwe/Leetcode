class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& g, int k) {
        int sum = 0;
        for (int i=0; i!=g.size(); i++)
        {
            int minrow = 1e9;
            for (int j=0; j!=g[i].size(); j++)
            {
                minrow = min(minrow, g[i][j]);
            }
            sum += minrow;
        }
        if (sum >= k) return sum - k;
        vector<int> prev(2*k+1, 0), next = prev, zero = prev;
        int ma = 1e9, minrow = 1e9;
        for (int i=0; i!=g.size(); i++)
        {
            if (i == 0)
            {
                for (int j=0; j!=g[i].size(); j++)
                {
                    if (g[i][j] <= 2*k) next[g[i][j]] = 1;
                }
            }
            else
            {
                for (int j=0; j!=g[i].size(); j++)
                {
                    for (int a = 0; a<prev.size(); a++)
                    {
                        if (prev[a] == 1 && g[i][j] + a <= 2*k) next[g[i][j] + a] = 1;
                    }
                }
            }
            prev = next;
            next = zero;
        }
        int ans = 1e9;
        for (int i = 2*k; i>=0; i--) if (prev[i] == 1)
        {
            ans = min(ans, abs(k - i));
        }
        return ans;
    }
};