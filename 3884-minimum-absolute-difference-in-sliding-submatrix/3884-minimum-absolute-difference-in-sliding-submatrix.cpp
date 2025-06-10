class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        vector<vector<int>> ans(g.size() + 1 - k, vector<int>(g[0].size() + 1 - k, 0));
        if (k > 1) for (int i=0; i<ans.size(); i++)
        {
            for (int j=0; j<ans[0].size(); j++)
            {
                vector<int> t;
                for (int a=0; a<k; a++)
                {
                    for (int b=0; b<k; b++)
                    {
                        t.push_back(g[i+a][j+b]);
                    }
                }
                sort(t.begin(), t.end());
                int tt = 1e6;
                if (t[0] == t.back()) tt = 0;
                else
                {
                    int prev = t[0];
                    for (int a=1; a<t.size(); a++)
                    {
                        if (t[a] != prev) tt = min(tt, t[a] - prev);
                        prev = t[a];
                    }
                }
                ans[i][j] = tt;
            }
        }
        return ans;
    }
};