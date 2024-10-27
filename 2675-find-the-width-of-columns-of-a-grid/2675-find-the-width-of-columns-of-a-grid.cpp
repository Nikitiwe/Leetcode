class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& g) {
        vector<int> ans(g[0].size(), 0);
        for (int j=0; j!=g[0].size(); j++)
        {
            int t=0;
            for (int i=0; i!=g.size(); i++)
            {
                string s=to_string(g[i][j]);
                t=max(t, (int)s.size());
            }
            ans[j]=t;
        }
        return ans;
    }
};