class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& g) {
        for (int i=0; i!=g.size(); i++)
        {
            if (g[i][i]==0) return 0;
            if (g[g.size()-1-i][i]==0) return 0;
        }
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if ((i!=j&&i+j!=g.size()-1)&&g[i][j]!=0) return 0;
            }
        }
        return 1;
    }
};