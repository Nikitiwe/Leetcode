class Solution {
public:
    int minMoves(vector<string>& g) {
        if (g[g.size() - 1][g[0].size() - 1] == '#') return -1;
        vector<vector<pair<int, int>>> arr(26, vector<pair<int, int>>());
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[i].size(); j++)
            {
                if (g[i][j] != '.' && g[i][j] != '#') arr[g[i][j] - 'A'].push_back({i, j});
            }
        }
        deque<pair<int, int>> q; // х, у
        q.push_back({0, 0});
        vector<vector<int>> m(g.size(), vector<int>(g[0].size(), 10000));
        vector<bool> isit(26, 1);
        m[0][0] = 0;
        while (q.size() > 0)
        {
            auto [x, y] = q.front();
            int l = m[x][y];
            q.pop_front();
            if (g[x][y] != '#')
            {
                if (x > 0 && m[x-1][y] > l+1)
                {
                    q.push_back({x-1, y});
                    m[x-1][y] = l+1;
                }
                if (y > 0 && m[x][y-1] > l+1)
                {
                    q.push_back({x, y-1});
                    m[x][y-1] = l+1;
                }
                if (x+1 < g.size() && m[x+1][y] > l+1)
                {
                    q.push_back({x+1, y});
                    m[x+1][y] = l+1;
                }
                if (y+1 < g[0].size() && m[x][y+1] > l+1)
                {
                    q.push_back({x, y+1});
                    m[x][y+1] = l+1;
                }
            }
            if (g[x][y] != '.' && g[x][y] != '#')
            {
                auto id = g[x][y] - 'A';
                if (isit[id] == 1)
                {
                    isit[id] = 0;
                    for (int i=0; i<arr[id].size(); i++)
                    {
                        auto [a, b] = arr[id][i];
                        if (m[a][b] > l)
                        {
                            q.push_front({a, b});
                            m[a][b] = l;
                        }
                    }
                }
            }
        }
        if (m[g.size() - 1][g[0].size() - 1] < 10000) return m[g.size() - 1][g[0].size() - 1];
        else return -1;
    }
};