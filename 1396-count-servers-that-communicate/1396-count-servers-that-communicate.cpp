class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowsum(grid.size(), 0), colsum(grid[0].size(), 0);
        int ans=0;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                rowsum[i]+=grid[i][j];
                colsum[j]+=grid[i][j];
            }
        }
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (grid[i][j]==1&&(rowsum[i]>1||colsum[j]>1)) ans++;
            }
        }
        return ans;
    }
};