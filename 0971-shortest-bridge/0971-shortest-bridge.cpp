class Solution {
public:
    int shortestBridge(vector<vector<int>>& g) {
        queue<pair<int, int>> q, w;
        unordered_set<int> s;
        unordered_map<int, int> m;
        for (int i=0; i!=g.size(); i++)
        {
            bool isit = 0;
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] == 1)
                {
                    q.push({i, j});
                    s.insert(100*i+j);
                    isit = 1;
                    break;
                }
            }
            if (isit == 1) break;
        }
        while (q.size() > 0)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (x>0 && s.count(100*(x-1)+y) == 0)
            {
                if (g[x-1][y] == 1)
                {
                    q.push({x-1, y});
                    s.insert(100*(x-1)+y);
                }
                else
                {
                    w.push({x-1, y});
                    m[100*(x-1)+y] = 1;
                    s.insert(100*(x-1)+y);
                }
            }
            if (y>0 && s.count(100*(x)+y-1) == 0)
            {
                if (g[x][y-1] == 1)
                {
                    q.push({x, y-1});
                    s.insert(100*(x)+y-1);
                }
                else
                {
                    w.push({x, y-1});
                    m[100*(x)+y-1] = 1;
                    s.insert(100*(x)+y-1);
                }
            }
            if (x<g.size()-1 && s.count(100*(x+1)+y) == 0)
            {
                if (g[x+1][y] == 1)
                {
                    q.push({x+1, y});
                    s.insert(100*(x+1)+y);
                }
                else
                {
                    w.push({x+1, y});
                    m[100*(x+1)+y] = 1;
                    s.insert(100*(x+1)+y);
                }
            }
            if (y<g[0].size()-1 && s.count(100*(x)+y+1) == 0)
            {
                if (g[x][y+1] == 1)
                {
                    q.push({x, y+1});
                    s.insert(100*(x)+y+1);
                }
                else
                {
                    w.push({x, y+1});
                    m[100*(x)+y+1] = 1;
                    s.insert(100*(x)+y+1);
                }
            }
        }
        while (w.size() > 0)
        {
            int x = w.front().first, y = w.front().second;
            int d = m[100*(x)+y];
            w.pop();
            if (x>0 && s.count(100*(x-1)+y) == 0)
            {
                if (g[x-1][y] == 1)
                {
                    return d;
                }
                else
                {
                    w.push({x-1, y});
                    m[100*(x-1)+y] = d+1;
                    s.insert(100*(x-1)+y);
                }
            }
            if (y>0 && s.count(100*(x)+y-1) == 0)
            {
                if (g[x][y-1] == 1)
                {
                    return d;
                }
                else
                {
                    w.push({x, y-1});
                    m[100*(x)+y-1] = d+1;
                    s.insert(100*(x)+y-1);
                }
            }
            if (x<g.size()-1 && s.count(100*(x+1)+y) == 0)
            {
                if (g[x+1][y] == 1)
                {
                    return d;
                }
                else
                {
                    w.push({x+1, y});
                    m[100*(x+1)+y] = d+1;
                    s.insert(100*(x+1)+y);
                }
            }
            if (y<g[0].size()-1 && s.count(100*(x)+y+1) == 0)
            {
                if (g[x][y+1] == 1)
                {
                    return d;
                }
                else
                {
                    w.push({x, y+1});
                    m[100*(x)+y+1] = d+1;
                    s.insert(100*(x)+y+1);
                }
            }
        }
        return -1;
    }
};