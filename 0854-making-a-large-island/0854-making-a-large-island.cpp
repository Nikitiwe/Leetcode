class Solution {
public:
    int largestIsland(vector<vector<int>>& g) {
        int ans = 1;
        //unordered_set<int> arr;
        int k = 2;
        unordered_map<int, int> s;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] == 1)
                {
                    int area = 0;
                    queue<int> x, y;
                    x.push(i);
                    y.push(j);
                    g[i][j] = k;
                    area++;
                    while(x.size() > 0)
                    {
                        int a = x.front(); x.pop();
                        int b = y.front(); y.pop();
                        /*if (a > 1 && g[a-1][b] == 0 && g[a-2][b] > 1 && g[a-2][b] < k) arr.insert(k*100000 + g[a-2][b]);
                        if (a > 0 && b > 0 && g[a-1][b] == 0 && g[a-1][b-1] > 1 && g[a-1][b-1] < k) arr.insert(k*100000 + g[a-1][b-1]);
                        if (a > 0 && b+1 < g[0].size() && g[a-1][b] == 0 && g[a-1][b+1] > 1 && g[a-1][b+1] < k) arr.insert(k*100000 + g[a-1][b+1]);
                        if (b > 1 && g[a][b-1] == 0 && g[a][b-2] > 1 && g[a][b-2] < k) arr.insert(k*100000 + g[a][b-2]);
                        if (b > 0 && a+1 < g.size() && g[a][b-1] == 0 && g[a+1][b-1] > 1 && g[a+1][b-1] < k) arr.insert(k*100000 + g[a+1][b-1]);
                        if (b+1 < g[0].size() && a+1 < g.size() && g[a][b+1] == 0 && g[a+1][b+1] > 1 && g[a+1][b+1] < k) arr.insert(k*100000 + g[a+1][b+1]);
                        if (a+2 < g.size() && g[a+1][b] == 0 && g[a+2][b] > 1 && g[a+2][b] < k) arr.insert(k*100000 + g[a+2][b]);
                        if (b+2 < g[0].size() && g[a][b+1] == 0 && g[a][b+2] > 1 && g[a][b+2] < k) arr.insert(k*100000 + g[a][b+2]);*/
                        if (a > 0 && g[a-1][b] == 1)
                        {
                            x.push(a-1);
                            y.push(b);
                            g[a-1][b] = k;
                            area++;
                        }
                        if (b > 0 && g[a][b-1] == 1)
                        {
                            x.push(a);
                            y.push(b-1);
                            g[a][b-1] = k;
                            area++;
                        }
                        if (a+1 < g.size() && g[a+1][b] == 1)
                        {
                            x.push(a+1);
                            y.push(b);
                            g[a+1][b] = k;
                            area++;
                        }
                        if (b+1 < g[0].size() && g[a][b+1] == 1)
                        {
                            x.push(a);
                            y.push(b+1);
                            g[a][b+1] = k;
                            area++;
                        }
                    }
                    s[k] = area;
                    ans = max(ans, s[k]);
                    k++;
                }
            }
        }
        /*for (auto i=arr.begin(); i!=arr.end(); i++)
        {
            ans = max(ans, 1 + s[(*i)/100000] + s[(*i)%100000]);
        }*/
        //return s[4];
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] == 0)
                {
                    int t = 1;
                    unordered_set<int> n;
                    if (i > 0 && g[i-1][j] != 0) n.insert(g[i-1][j]);
                    if (j > 0 && g[i][j-1] != 0) n.insert(g[i][j-1]);
                    if (i+1 < g.size() && g[i+1][j] != 0) n.insert(g[i+1][j]);
                    if (j+1 < g[0].size() && g[i][j+1] != 0) n.insert(g[i][j+1]);
                    for (auto i=n.begin(); i!=n.end(); i++) t += s[(*i)];
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};