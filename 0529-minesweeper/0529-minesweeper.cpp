class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& g, vector<int>& turn) {
        if (g[turn[0]][turn[1]] == 'M')
        {
            g[turn[0]][turn[1]] = 'X';
        }
        else
        {
            unordered_set<int> m;
            queue<int> x, y;
            x.push(turn[0]);
            y.push(turn[1]);
            m.insert(100*turn[0]+turn[1]);
            while (x.size() > 0)
            {
                int a = x.front(), b = y.front();
                x.pop(); y.pop();
                if (g[a][b] == 'M') g[a][b] = 'X';
                else
                {
                    int count = 0;
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (a+dx>=0 && a+dx < g.size() && b+dy>=0 && b+dy < g[0].size() && (g[a+dx][b+dy] == 'M' || g[a+dx][b+dy] == 'X') ) count++;
                        }
                    }
                    if (count == 0)
                    {
                        g[a][b] = 'B';
                        for (int dx = -1; dx <= 1; dx++)
                        {
                            for (int dy = -1; dy <= 1; dy++)
                            {
                                if (dx != 0 || dy != 0)
                                {
                                    if (a+dx>=0 && a+dx < g.size() && b+dy>=0 && b+dy < g[0].size() && m.count(100*(a+dx)+b+dy) == 0)
                                    {
                                        x.push(a+dx);
                                        y.push(b+dy);
                                        m.insert(100*(a+dx)+b+dy);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        g[a][b] = count + '0';
                    }
                }
            }
        }
        return g;
    }
};