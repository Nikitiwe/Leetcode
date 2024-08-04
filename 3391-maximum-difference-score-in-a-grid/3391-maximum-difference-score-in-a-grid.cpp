class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> m=grid;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=grid[0].size()-2; j>=0; j--)
            {
                m[i][j]=max(m[i][j], m[i][j+1]);
            }
        }
        for (int i=grid.size()-2; i>=0; i--)
        {
            for (int j=grid[0].size()-1; j>=0; j--)
            {
                m[i][j]=max(m[i][j], m[i+1][j]);
            }
        }
        int ans=-10000000;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (i<grid.size()-1) ans=max(ans, m[i+1][j]-grid[i][j]);
                if (j<grid[0].size()-1) ans=max(ans, m[i][j+1]-grid[i][j]);
            }
        }
        return ans;
    }
};