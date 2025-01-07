class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& g) {
        int ans=0;
        vector<priority_queue<int>> m(g.size(), priority_queue<int>());
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                m[i].push(g[i][j]);
            }
        }
        for (int k=0; k<g[0].size(); k++)
        {
            int t=0;
            for (int i=0; i!=g.size(); i++)
            {
                t=max(t, m[i].top());
                m[i].pop();
            }
            ans+=t;
        }
        return ans;
    }
};