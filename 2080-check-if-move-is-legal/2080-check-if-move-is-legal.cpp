class Solution {
public:
    bool checkMove(vector<vector<char>>& g, int xx, int yy, char c) {
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (dx != 0 || dy != 0)
                {
                    bool ism = 0;
                    int x = xx, y = yy;
                    x += dx;
                    y += dy;
                    while ( x>=0 && x<g.size() && y>=0 && y<g[0].size())
                    {
                        if (g[x][y] == '.') break;
                        if (g[x][y] == c && ism != 1) break;
                        if (g[x][y] != c) ism = 1;
                        if (g[x][y] == c && ism == 1) return 1;
                        x += dx;
                        y += dy;
                    }
                }
            }
        }
        return 0;
    }
};