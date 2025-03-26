class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        queue<pair<int, int>> q;
        unordered_map<int, int> s;
        if (g[0][0] == 0)
        {
            q.push({0, 0});
            s[0] = -1;
        }
        while (q.size() > 0)
        {
            int x = q.front().first, y = q.front().second;
            for (int i=-1; i<=1; i++)
            {
                for (int j=-1; j<=1; j++)
                {
                    if (x+i >= 0 && x+i < g.size() && y+j>=0 && y+j < g[0].size() && g[x+i][y+j] == 0 && s.count(100*(x+i) + y+j) == 0)
                    {
                        q.push({x+i, y+j});
                        s[100*(x+i) + y+j] = s[100*x + y] - 1;
                    }
                }
            }
            q.pop();
        }
        if (s.count(100*(g.size()-1) + g.size() - 1) == 0) return -1;
        else return -s[100*(g.size()-1) + g.size() - 1];
    }
};