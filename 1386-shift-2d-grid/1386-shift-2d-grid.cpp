class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        vector<vector<int>> ans=g;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                int t=i*g[0].size()+j+k;
                ans[(t/g[0].size())%g.size()][t%g[0].size()]=g[i][j];
            }
        }
        return ans;
    }
};