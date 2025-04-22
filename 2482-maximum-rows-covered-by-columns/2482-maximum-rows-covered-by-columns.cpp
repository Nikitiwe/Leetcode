class Solution {
public:
    int maximumRows(vector<vector<int>>& gg, int k) {
        int a = 1;
        int ans = 0;
        for (int i=0; i!=gg[0].size(); i++) a *= 2;
        for (int b = 0; b<a; b++)
        {
            int t = b;
            int c = 0;
            vector<vector<int>> g = gg;
            for (int j=0; j!=g[0].size(); j++)
            {
                if (t % 2 == 1)
                {
                    c++;
                    for (int i=0; i!=g.size(); i++)
                    {
                        g[i][j] = 0;
                    }
                }
                t /= 2;
            }
            if (c == k)
            {
                int temp = 0;
                for (int i=0; i!=g.size(); i++)
                {
                    int sum = 0;
                    for (int j=0; j!=g[0].size(); j++)
                    {
                        sum += g[i][j];
                    }
                    if (sum == 0)  temp++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};