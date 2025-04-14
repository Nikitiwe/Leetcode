class Solution {
public:
    long long f(int a, int b)
    {
        return (long long)a*1000000 + b;
    }
    int minimumObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<int> x, y;
        unordered_map<long long, int> ans;
        x.push(0);
        y.push(0);
        ans[0] = 0;
        while (x.size() > 0)
        {
            int a = x.front(), b = y.front();
            x.pop(); y.pop();
            int t = ans[f(a, b)];
            if (a > 0 && g[a-1][b] == 0 && (ans.count(f(a-1, b)) == 0 || ans[f(a-1, b)] > t))
            {
                x.push(a-1);
                y.push(b);
                ans[f(a-1, b)] = t;
            }
            else if (a > 0 && g[a-1][b] == 1 && (ans.count(f(a-1, b)) == 0 || ans[f(a-1, b)] > t + 1))
            {
                x.push(a-1);
                y.push(b);
                ans[f(a-1, b)] = t + 1;
            }

            if (b > 0 && g[a][b-1] == 0 && (ans.count(f(a, b-1)) == 0 || ans[f(a, b-1)] > t))
            {
                x.push(a);
                y.push(b-1);
                ans[f(a, b-1)] = t;
            }
            else if (b > 0 && g[a][b-1] == 1 && (ans.count(f(a, b-1)) == 0 || ans[f(a, b-1)] > t + 1))
            {
                x.push(a);
                y.push(b-1);
                ans[f(a, b-1)] = t + 1;
            }

            if (a+1 < n && g[a+1][b] == 0 && (ans.count(f(a+1, b)) == 0 || ans[f(a+1, b)] > t))
            {
                x.push(a+1);
                y.push(b);
                ans[f(a+1, b)] = t;
            }
            else if (a+1 < n && g[a+1][b] == 1 && (ans.count(f(a+1, b)) == 0 || ans[f(a+1, b)] > t + 1))
            {
                x.push(a+1);
                y.push(b);
                ans[f(a+1, b)] = t + 1;
            }

            if (b+1 < m && g[a][b+1] == 0 && (ans.count(f(a, b+1)) == 0 || ans[f(a, b+1)] > t))
            {
                x.push(a);
                y.push(b+1);
                ans[f(a, b+1)] = t;
            }
            else if (b+1 < m && g[a][b+1] == 1 && (ans.count(f(a, b+1)) == 0 || ans[f(a, b+1)] > t + 1))
            {
                x.push(a);
                y.push(b+1);
                ans[f(a, b+1)] = t + 1;
            }            
        }
        return ans[f(n-1, m-1)];
    }
};