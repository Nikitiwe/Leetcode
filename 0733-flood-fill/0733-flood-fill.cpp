class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int c) {
        stack<pair<int, int>> m;
        unordered_set<int> s;
        int t=g[sr][sc];
        g[sr][sc]=c;
        m.push({sr, sc});
        s.insert(sr*100+sc);
        while (m.size()>0)
        {
            int x=m.top().first, y=m.top().second;
            m.pop();
            if (x>0&&g[x-1][y]==t&&s.count((x-1)*100+y)==0)
            {
                m.push({x-1, y});
                g[x-1][y]=c;
                s.insert((x-1)*100+y);
            }
            if (y>0&&g[x][y-1]==t&&s.count((x)*100+y-1)==0)
            {
                m.push({x, y-1});
                g[x][y-1]=c;
                s.insert((x)*100+y-1);
            }
            if (x<g.size()-1&&g[x+1][y]==t&&s.count((x+1)*100+y)==0)
            {
                m.push({x+1, y});
                g[x+1][y]=c;
                s.insert((x+1)*100+y);
            }
            if (y<g[0].size()-1&&g[x][y+1]==t&&s.count((x)*100+y+1)==0)
            {
                m.push({x, y+1});
                g[x][y+1]=c;
                s.insert((x)*100+y+1);
            }
        }
        return g;
    }
};