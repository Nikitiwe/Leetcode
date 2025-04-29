class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& s) {
        queue<int> x, y, l;
        x.push(s[0]);
        y.push(s[1]);
        l.push(0);
        g[s[0]][s[1]] = 'b';
        while (x.size() > 0)
        {
            int a = x.front(); x.pop();
            int b = y.front(); y.pop();
            int ans = l.front(); l.pop();
            if ( (a == 0 || a+1 == g.size() || b == 0 || b+1 == g[0].size()) && (a != s[0] || b != s[1])) return ans;
            if (a > 0 && g[a-1][b] == '.')
            {
                x.push(a-1);
                y.push(b);
                l.push(ans+1);
                g[a-1][b] = 'b';
            }
            if (b > 0 && g[a][b-1] == '.')
            {
                x.push(a);
                y.push(b-1);
                l.push(ans+1);
                g[a][b-1] = 'b';
            }
            if (a+1 < g.size() && g[a+1][b] == '.')
            {
                x.push(a+1);
                y.push(b);
                l.push(ans+1);
                g[a+1][b] = 'b';
            }
            if (b+1 < g[0].size() && g[a][b+1] == '.')
            {
                x.push(a);
                y.push(b+1);
                l.push(ans+1);
                g[a][b+1] = 'b';
            }
        }
        return -1;
    }
};