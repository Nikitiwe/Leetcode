class Solution {
public:
    bool f(vector<vector<char>> &g, int i, int j)
    {
        if (i == 9) return 1;
        if (g[i][j] != '.')
        {
            if (j < 8) return f(g, i, j+1);
            else return f(g, i+1, 0);
        }
        for (int k=1; k <= 9; k++)
        {
            bool isit = 1;
            char t = '0' + k;
            for (int x = 0; x<9; x++)
            {
                if (x != i)
                {
                    if (g[x][j] == t)
                    {
                        isit = 0;
                        break;
                    }
                }
            }
            if (isit == 1) for (int y = 0; y<9; y++)
            {
                if (y != j)
                {
                    if (g[i][y] == t)
                    {
                        isit = 0;
                        break;
                    }
                }
            }
            if (isit == 1)
            {
                int a = 0, b = 0;
                if (i>2) a += 3; if (i>5) a += 3;
                if (j>2) b += 3; if (j>5) b += 3;
                for (int x = 0; x<3; x++)
                {
                    for (int y = 0; y<3; y++)
                    {
                        if (a+x != i || b+y != j)
                        {
                            if (g[a+x][b+y] == t)
                            {
                                isit = 0;
                                break;
                            }
                        }
                    }
                    if (isit == 0) break;
                }
            }
            if (isit == 1)
            {
                g[i][j] = t;
                int ii = i, jj = j;
                if (jj < 8) jj++;
                else
                {
                    ii++;
                    jj = 0;
                }
                bool ans = f(g, ii, jj);
                if (ans == 1) return 1;
                g[i][j] = '.';
            }
        }
        return 0;
    }

    void solveSudoku(vector<vector<char>>& g) {
        f(g, 0, 0);
    }
};