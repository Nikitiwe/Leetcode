class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        unordered_map<int, int> m;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (m.count(1000*i + j) == 0)//   1
                {                            // 4   2
                    char c = g[i][j];        //   3
                    queue<pair<int, int>> q;
                    queue<int> t, p;
                    q.push({i, j});
                    t.push(0);
                    p.push(0);
                    while (q.size() > 0)
                    {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        int k = t.front();
                        t.pop();
                        int d = p.front();
                        p.pop();
                        if (m.count(1000*x + y) == 0) m[1000*x + y] = k;
                        else if (k - m[1000*x + y] >= 4) return 1;
                        if (d != 1) if (x > 0 && g[x-1][y] == c)
                        {
                            if (m.count(1000*(x-1) + y) == 0)
                            {
                                q.push({x-1, y});
                                t.push(k+1);
                                p.push(3);
                                m[1000*(x-1) + y] = k+1;
                            }
                            //else if (k + 1 - m[1000*(x-1) + y] >= 4) return 1;
                            else return 1;
                        }
                        if (d != 4) if (y > 0 && g[x][y-1] == c)
                        {
                            if (m.count(1000*(x) + y - 1) == 0)
                            {
                                q.push({x, y-1});
                                t.push(k+1);
                                p.push(2);
                                m[1000*(x) + y-1] = k+1;
                            }
                            //else if (k + 1 - m[1000*(x) + y-1] >= 4) return 1;
                            else return 1;
                        }
                        if (d != 3) if (x < g.size() - 1 && g[x+1][y] == c)
                        {
                            if (m.count(1000*(x+1) + y) == 0)
                            {
                                q.push({x+1, y});
                                t.push(k+1);
                                p.push(1);
                                m[1000*(x+1) + y] = k+1;
                            }
                            //else if (k + 1 - m[1000*(x+1) + y] >= 4) return 1;
                            else return 1;
                        }
                        if (d != 2) if (y < g[0].size() - 1 && g[x][y+1] == c)
                        {
                            if (m.count(1000*(x) + y + 1) == 0)
                            {
                                q.push({x, y+1});
                                t.push(k+1);
                                p.push(4);
                                m[1000*(x) + y+1] = k+1;
                            }
                            //else if (k + 1 - m[1000*(x) + y+1] >= 4) return 1;
                            else return 1;
                        }
                    }
                }                
            }
        }
        return 0;
    }
};