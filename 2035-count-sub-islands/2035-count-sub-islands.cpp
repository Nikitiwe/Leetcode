class Solution {
public:
    int countSubIslands(vector<vector<int>>& g, vector<vector<int>>& f) {
        int ans = 0;
        for (int i=0; i!=f.size(); i++)
        {
            for (int j=0; j!=f[0].size(); j++)
            {
                if (f[i][j] == 1 && g[i][j] == 1)
                {
                    queue<int> x, y;
                    x.push(i);
                    y.push(j);
                    g[i][j] = 0;
                    f[i][j] = 0;
                    bool isit = 1;
                    while(x.size() > 0)
                    {
                        int a = x.front(), b = y.front();
                        x.pop();
                        y.pop();
                        if (a>0 && g[a-1][b] == 1 && f[a-1][b] == 1)
                        {
                            x.push(a-1);
                            y.push(b);
                            g[a-1][b] = 0;
                            f[a-1][b] = 0;
                        }
                        else if (a>0 && g[a-1][b] == 0 && f[a-1][b] == 1)
                        {
                            isit = 0;
                        }
                        if (b>0 && g[a][b-1] == 1 && f[a][b-1] == 1)
                        {
                            x.push(a);
                            y.push(b-1);
                            g[a][b-1] = 0;
                            f[a][b-1] = 0;
                        }
                        else if (b>0 && g[a][b-1] == 0 && f[a][b-1] == 1)
                        {
                            isit = 0;
                        }
                        if (a<g.size()-1 && g[a+1][b] == 1 && f[a+1][b] == 1)
                        {
                            x.push(a+1);
                            y.push(b);
                            g[a+1][b] = 0;
                            f[a+1][b] = 0;
                        }
                        else if (a<g.size()-1 && g[a+1][b] == 0 && f[a+1][b] == 1)
                        {
                            isit = 0;
                        }
                        if (b<g[0].size()-1 && g[a][b+1] == 1 && f[a][b+1] == 1)
                        {
                            x.push(a);
                            y.push(b+1);
                            g[a][b+1] = 0;
                            f[a][b+1] = 0;
                        }
                        else if (b<g[0].size()-1 && g[a][b+1] == 0 && f[a][b+1] == 1)
                        {
                            isit = 0;
                        }
                    }
                    if (isit == 1) ans++;
                }
            }
        }
        return ans;
    }
};