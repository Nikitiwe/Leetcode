class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> ru(n, vector<int>(m, 0)), rd = ru, lu = ru, ld = ru;
        for (int i=n-1; i>=0; i--)
        {
            for (int j=m-1; j>=0; j--)
            {
                if (g[i][j] != 1)
                {
                    int l = 0;
                    for (int a = 1; a+i < n && a+j < m; a++)
                    {
                        if (g[i+a][j+a] + g[i+a-1][j+a-1] != 2) break;
                        l = rd[i+1][j+1] + 1;
                        break;
                    }
                    rd[i][j] = l;
                }
            }
        }
        for (int i=n-1; i>=0; i--)
        {
            for (int j=0; j!=m; j++)
            {
                if (g[i][j] != 1)
                {
                    int l = 0;
                    for (int a = 1; a+i < n && j-a >= 0; a++)
                    {
                        if (g[i+a][j-a] + g[i+a-1][j-a+1] != 2) break;
                        l = ld[i+1][j-1] + 1;
                        break;
                    }
                    ld[i][j] = l;
                }
            }
        }
        for (int i=0; i!=n; i++)
        {
            for (int j=m-1; j>=0; j--)
            {
                if (g[i][j] != 1)
                {
                    int l = 0;
                    for (int a = 1; i-a >= 0 && a+j < m; a++)
                    {
                        if (g[i-a][j+a] + g[i-a+1][j+a-1] != 2) break;
                        l = ru[i-1][j+1] + 1;
                        break;
                    }
                    ru[i][j] = l;
                }
            }
        }
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=m; j++)
            {
                if (g[i][j] != 1)
                {
                    int l = 0;
                    for (int a = 1; i-a >= 0 && j-a >= 0; a++)
                    {
                        if (g[i-a][j-a] + g[i-a+1][j-a+1] != 2) break;
                        l = lu[i-1][j-1] + 1;
                        break;
                    }
                    lu[i][j] = l;
                }
            }
        }
        int ans = 0;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=m; j++)
            {
                if (g[i][j] == 1)
                {
                    ans = max(ans, 1);
                    for (int a = 1; a+i < n && a+j < m; a++)
                    {
                        if (a % 2 == 1)
                        {
                            if (g[i+a][j+a] == 2)
                            {
                                //ans = max(ans, 1 + a + ru[i+a][j+a]);
                                ans = max(ans, 1 + a + ld[i+a][j+a]);
                            }
                            else break;
                        }
                        else
                        {
                            if (g[i+a][j+a] == 0)
                            {
                                //ans = max(ans, 1 + a + ru[i+a][j+a]);
                                ans = max(ans, 1 + a + ld[i+a][j+a]);
                            }
                            else break;
                        }
                    }
                    for (int a = 1; i-a >=0 && j-a >= 0; a++)
                    {
                        if (a % 2 == 1)
                        {
                            if (g[i-a][j-a] == 2)
                            {
                                ans = max(ans, 1 + a + ru[i-a][j-a]);
                                //ans = max(ans, 1 + a + ld[i-a][j-a]);
                            }
                            else break;
                        }
                        else
                        {
                            if (g[i-a][j-a] == 0)
                            {
                                ans = max(ans, 1 + a + ru[i-a][j-a]);
                                //ans = max(ans, 1 + a + ld[i-a][j-a]);
                            }
                            else break;
                        }
                    }
                    for (int a = 1; a+i < n && j-a >= 0; a++)
                    {
                        if (a % 2 == 1)
                        {
                            if (g[i+a][j-a] == 2)
                            {
                                //ans = max(ans, 1 + a + rd[i+a][j-a]);
                                ans = max(ans, 1 + a + lu[i+a][j-a]);
                            }
                            else break;
                        }
                        else
                        {
                            if (g[i+a][j-a] == 0)
                            {
                                //ans = max(ans, 1 + a + rd[i+a][j-a]);
                                ans = max(ans, 1 + a + lu[i+a][j-a]);
                            }
                            else break;
                        }
                    }
                    for (int a = 1; i-a >=0 && a+j < m; a++)
                    {
                        if (a % 2 == 1)
                        {
                            if (g[i-a][j+a] == 2)
                            {
                                ans = max(ans, 1 + a + rd[i-a][j+a]);
                                //ans = max(ans, 1 + a + lu[i-a][j+a]);
                            }
                            else break;
                        }
                        else
                        {
                            if (g[i-a][j+a] == 0)
                            {
                                ans = max(ans, 1 + a + rd[i-a][j+a]);
                                //ans = max(ans, 1 + a + lu[i-a][j+a]);
                            }
                            else break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};