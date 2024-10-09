class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                if ((j<grid[0].size()-1&&grid[i][j]==grid[i][j+1])||(i<grid.size()-1&&grid[i][j]!=grid[i+1][j]))
                {
                    return 0;
                }
                //else if (j<grid[0].size()-1) return 0;
            }
        }
        return 1;
    }
};