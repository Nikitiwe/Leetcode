class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& g) {
        vector<int> ans;
        int c = 0;
        for (int i=0; i!=g.size(); i++)
        {
            if (i%2==0) for (int j=0; j!=g[0].size(); j++)
            {
                if (c%2==0) ans.push_back(g[i][j]);
                c++;
            }
            else for (int j=g[0].size()-1; j>=0; j--)
            {
                if (c%2==0) ans.push_back(g[i][j]);
                c++;
            }
        }
        return ans;
    }
};