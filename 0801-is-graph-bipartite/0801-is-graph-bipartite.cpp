class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        unordered_set<int> f, s;
        queue<int> qf, qs;
        while (f.size() + s.size() < g.size() || qf.size() + qs.size() > 0)
        {
            int count = f.size() + s.size();
            if (f.count(0) == 0)
            {
                f.insert(0);
                qf.push(0);
            }
            while (qf.size() > 0)
            {
                int t = qf.front(); qf.pop();
                //if (s.count(t) == 1) return 0;
                for (int i=0; i!=g[t].size(); i++)
                {
                    if (f.count(g[t][i]) != 0) return 0;
                    if (s.count(g[t][i]) == 0)
                    {
                        s.insert(g[t][i]);
                        qs.push(g[t][i]);
                    }
                }
            }
            while (qs.size() > 0)
            {
                int t = qs.front(); qs.pop();
                //if (f.count(t) == 1) return 0;
                for (int i=0; i!=g[t].size(); i++)
                {
                    if (s.count(g[t][i]) != 0) return 0;
                    if (f.count(g[t][i]) == 0)
                    {
                        f.insert(g[t][i]);
                        qf.push(g[t][i]);
                    }
                }
            }
            if (count == f.size() + s.size() && count < g.size())
            {
                for (int i=0; i!=g.size(); i++)
                {
                    if (f.count(i) == 0 && s.count(i) == 0 )
                    {
                        f.insert(i);
                        qf.push(i);
                        break;
                    }
                }
            }
        }
        return 1;
    }
};