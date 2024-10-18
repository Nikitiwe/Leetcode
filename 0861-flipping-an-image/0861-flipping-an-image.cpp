class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& g) {
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size()/2; j++)
            {
                swap(g[i][j], g[i][g[0].size()-1-j]);
            }
        }
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                g[i][j]^=1;
                /*if (g[i][j]==1) g[i][j]--;
                else g[i][j]++;*/
            }
        }
        return g;
    }
};