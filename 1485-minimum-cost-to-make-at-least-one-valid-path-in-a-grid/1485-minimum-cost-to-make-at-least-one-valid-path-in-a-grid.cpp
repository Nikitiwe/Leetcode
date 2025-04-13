class Solution {
public:
    int f(int x, int y)
    {
        return 1024*x + y;
    }
    int minCost(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<int> x, y;
        unordered_map<int, int> map;
        x.push(n-1);
        y.push(m-1);
        map[f(n-1, m-1)] = 0;
        while (x.size() > 0)
        {
            int a = x.front(), b = y.front();
            x.pop(); y.pop();
            if (a > 0 && g[a-1][b] == 3 && (map.count(f(a-1, b)) == 0 || map[f(a-1, b)] > map[f(a, b)]))
            {
                x.push(a-1);
                y.push(b);
                map[f(a-1, b)] = map[f(a, b)];
            }
            else if (a > 0 && g[a-1][b] != 3 && (map.count(f(a-1, b)) == 0 || map[f(a-1, b)] > map[f(a, b)] + 1))
            {
                x.push(a-1);
                y.push(b);
                map[f(a-1, b)] = map[f(a, b)] + 1;
            }
            if (b > 0 && g[a][b-1] == 1 && (map.count(f(a, b-1)) == 0 || map[f(a, b-1)] > map[f(a, b)]))
            {
                x.push(a);
                y.push(b-1);
                map[f(a, b-1)] = map[f(a, b)];
            }
            else if (b > 0 && g[a][b-1] != 1 && (map.count(f(a, b-1)) == 0 || map[f(a, b-1)] > map[f(a, b)] + 1))
            {
                x.push(a);
                y.push(b-1);
                map[f(a, b-1)] = map[f(a, b)] + 1;
            }
            if (a+1 < n && g[a+1][b] == 4 && (map.count(f(a+1, b)) == 0 || map[f(a+1, b)] > map[f(a, b)]))
            {
                x.push(a+1);
                y.push(b);
                map[f(a+1, b)] = map[f(a, b)];
            }
            else if (a+1 < n && g[a+1][b] != 4 && (map.count(f(a+1, b))== 0 || map[f(a+1, b)] > map[f(a, b)] + 1))
            {
                x.push(a+1);
                y.push(b);
                map[f(a+1, b)] = map[f(a, b)] + 1;
            }
            if (b+1 < m && g[a][b+1] == 2 && (map.count(f(a, b+1)) == 0 || map[f(a, b+1)] > map[f(a, b)]))
            {
                x.push(a);
                y.push(b+1);
                map[f(a, b+1)] = map[f(a, b)];
            }
            else if (b+1 < m && g[a][b+1] != 2 && (map.count(f(a, b+1)) == 0 || map[f(a, b+1)] > map[f(a, b)] + 1))
            {
                x.push(a);
                y.push(b+1);
                map[f(a, b+1)] = map[f(a, b)] + 1;
            }
        }
        return map[0];
    }
};