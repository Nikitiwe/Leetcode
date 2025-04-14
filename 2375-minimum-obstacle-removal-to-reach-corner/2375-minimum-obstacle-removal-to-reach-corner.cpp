class Solution {
public:
    long long f(int a, int b)
    {
        return (long long)a*1048576 + b;
    }
    int minimumObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        deque<int> x, y;
        unordered_map<long long, int> ans;
        x.push_front(0);
        y.push_front(0);
        ans[0] = 0;
        while (x.size() > 0)
        {
            int a = x.front(), b = y.front();
            x.pop_front(); y.pop_front();
            int t = ans[f(a, b)];
            if (a > 0 && g[a-1][b] == 0 && (ans.count(f(a-1, b)) == 0 || ans[f(a-1, b)] > t))
            {
                x.push_front(a-1);
                y.push_front(b);
                ans[f(a-1, b)] = t;
            }
            else if (a > 0 && g[a-1][b] == 1 && (ans.count(f(a-1, b)) == 0 || ans[f(a-1, b)] > t + 1))
            {
                x.push_back(a-1);
                y.push_back(b);
                ans[f(a-1, b)] = t + 1;
            }

            if (b > 0 && g[a][b-1] == 0 && (ans.count(f(a, b-1)) == 0 || ans[f(a, b-1)] > t))
            {
                x.push_front(a);
                y.push_front(b-1);
                ans[f(a, b-1)] = t;
            }
            else if (b > 0 && g[a][b-1] == 1 && (ans.count(f(a, b-1)) == 0 || ans[f(a, b-1)] > t + 1))
            {
                x.push_back(a);
                y.push_back(b-1);
                ans[f(a, b-1)] = t + 1;
            }

            if (a+1 < n && g[a+1][b] == 0 && (ans.count(f(a+1, b)) == 0 || ans[f(a+1, b)] > t))
            {
                x.push_front(a+1);
                y.push_front(b);
                ans[f(a+1, b)] = t;
            }
            else if (a+1 < n && g[a+1][b] == 1 && (ans.count(f(a+1, b)) == 0 || ans[f(a+1, b)] > t + 1))
            {
                x.push_back(a+1);
                y.push_back(b);
                ans[f(a+1, b)] = t + 1;
            }

            if (b+1 < m && g[a][b+1] == 0 && (ans.count(f(a, b+1)) == 0 || ans[f(a, b+1)] > t))
            {
                x.push_front(a);
                y.push_front(b+1);
                ans[f(a, b+1)] = t;
            }
            else if (b+1 < m && g[a][b+1] == 1 && (ans.count(f(a, b+1)) == 0 || ans[f(a, b+1)] > t + 1))
            {
                x.push_back(a);
                y.push_back(b+1);
                ans[f(a, b+1)] = t + 1;
            }
            if (ans.count(f(n-1, m-1)) != 0) return ans[f(n-1, m-1)];
        }
        return ans[f(n-1, m-1)];
    }
};