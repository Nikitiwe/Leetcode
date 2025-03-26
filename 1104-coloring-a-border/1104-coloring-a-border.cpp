class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int r, int c, int color) {
        int t = g[r][c];
        queue<pair<int, int>> q, b;
        unordered_set<int> s;
        q.push({r, c});
        s.insert(100*r + c);
        while (q.size() > 0)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if ( x == 0 || y == 0 || x == g.size()-1 || y == g[0].size()-1 ||
                (x>0 && g[x-1][y] != t) || (y>0 && g[x][y-1] != t) || 
                 (x<g.size()-1 && g[x+1][y] != t) || (y<g[0].size()-1 && g[x][y+1] != t) ) b.push({x, y});
            if ( x>0 && g[x-1][y] == g[x][y] && s.count(100*(x-1) + y) == 0 ) 
            {
                q.push({x-1, y});
                s.insert(100*(x-1) + y);
            }
            if ( y>0 && g[x][y-1] == g[x][y] && s.count(100*(x) + y-1) == 0)
            {
                q.push({x, y-1});
                s.insert(100*(x) + y - 1);
            }
            if ( x<g.size()-1 && g[x+1][y] == g[x][y] && s.count(100*(x+1) + y) == 0)
            {
                q.push({x+1, y});
                s.insert(100*(x+1) + y);
            }
            if ( y<g[0].size()-1 && g[x][y+1] == g[x][y] && s.count(100*(x) + y+1) == 0)
            {
                q.push({x, y+1});
                s.insert(100*(x) + y + 1);
            }
        }
        while (b.size() > 0)
        {
            int x = b.front().first, y = b.front().second;
            b.pop();
            g[x][y] = color;
        }
        return g;
    }
};