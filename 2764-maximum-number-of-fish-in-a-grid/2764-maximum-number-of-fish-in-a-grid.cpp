class Solution {
public:
    int findMaxFish(vector<vector<int>>& g) {
        int ans = 0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] > 0)
                {
                    int sum = 0;
                    queue<int> x, y;
                    x.push(i);
                    y.push(j);
                    while (x.size() > 0)
                    {
                        int a = x.front(), b = y.front();
                        x.pop(); y.pop();
                        sum += g[a][b];
                        g[a][b] = 0;
                        if (a > 0 && g[a-1][b] > 0)
                        {
                            x.push(a-1);
                            y.push(b);
                        }
                        if (b > 0 && g[a][b-1] > 0)
                        {
                            x.push(a);
                            y.push(b-1);
                        }
                        if (a+1 < g.size() && g[a+1][b] > 0)
                        {
                            x.push(a+1);
                            y.push(b);
                        }
                        if (b+1 < g[0].size() && g[a][b+1] > 0)
                        {
                            x.push(a);
                            y.push(b+1);
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};