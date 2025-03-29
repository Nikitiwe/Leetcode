class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& q) {
        vector<vector<int>> arr(q.size(), vector<int>(2, 0));
        for (int i=0; i!=q.size(); i++)
        {
            arr[i][0] = q[i];
            arr[i][1] = i;
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(q.size(), 0);
        queue<pair<int, int>> zero, one;
        unordered_set<int> s;
        zero.push({0, 0});
        s.insert(0);
        int t = 0;
        for (int i=0; i!=q.size(); i++)
        {
            if (i%2 == 0)
            {
                while (zero.size() > 0) // работаем с zero
                {
                    int k = arr[i][0];
                    int x = zero.front().first, y = zero.front().second;
                    zero.pop();
                    if (g[x][y] >= k) one.push({x, y}); // если стоим в большой клетке, то 
                    // отложить на потом
                    else // а если нет, то съесть и посмотреть соседей
                    {
                        t++;
                        if (x > 0 && s.count(1000*(x-1) + y) == 0)
                        {
                            s.insert(1000*(x-1) + y);
                            if (g[x-1][y] < k) zero.push({x-1, y});
                            else one.push({x-1, y});
                        }
                        if (y > 0 && s.count(1000*(x) + y - 1) == 0)
                        {
                            s.insert(1000*(x) + y - 1);
                            if (g[x][y-1] < k) zero.push({x, y-1});
                            else one.push({x, y-1});
                        }
                        if (x < g.size()-1 && s.count(1000*(x+1) + y) == 0)
                        {
                            s.insert(1000*(x+1) + y);
                            if (g[x+1][y] < k) zero.push({x+1, y});
                            else one.push({x+1, y});
                        }
                        if (y < g[0].size()-1 && s.count(1000*(x) + y + 1) == 0)
                        {
                            s.insert(1000*(x) + y + 1);
                            if (g[x][y+1] < k) zero.push({x, y+1});
                            else one.push({x, y+1});
                        }
                    }
                }
            }
            else // работаем с one
            {
                while (one.size() > 0)
                {
                    int k = arr[i][0];
                    int x = one.front().first, y = one.front().second;
                    one.pop();
                    if (g[x][y] >= k) zero.push({x, y}); // если стоим в большой клетке, то 
                    // отложить на потом
                    else // а если нет, то съесть и посмотреть соседей
                    {
                        t++;
                        if (x > 0 && s.count(1000*(x-1) + y) == 0)
                        {
                            s.insert(1000*(x-1) + y);
                            if (g[x-1][y] < k) one.push({x-1, y});
                            else zero.push({x-1, y});
                        }
                        if (y > 0 && s.count(1000*(x) + y - 1) == 0)
                        {
                            s.insert(1000*(x) + y - 1);
                            if (g[x][y-1] < k) one.push({x, y-1});
                            else zero.push({x, y-1});
                        }
                        if (x < g.size()-1 && s.count(1000*(x+1) + y) == 0)
                        {
                            s.insert(1000*(x+1) + y);
                            if (g[x+1][y] < k) one.push({x+1, y});
                            else zero.push({x+1, y});
                        }
                        if (y < g[0].size()-1 && s.count(1000*(x) + y + 1) == 0)
                        {
                            s.insert(1000*(x) + y + 1);
                            if (g[x][y+1] < k) one.push({x, y+1});
                            else zero.push({x, y+1});
                        }
                    }
                }
            }
            ans[arr[i][1]] = t;
            int a = 0;
            while (i + a + 2 < q.size() && arr[i][0] == arr[i+a+2][0]) a += 2;
            if (i + a < q.size() && arr[i][0] == arr[i+a][0])
            {
                for (int j=1; j<=a; j++) ans[arr[i+j][1]] = t;
                i += a;
            }
        }
        return ans;
    }
};