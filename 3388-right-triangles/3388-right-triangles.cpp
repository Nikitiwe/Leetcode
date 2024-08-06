class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> row, col;
        int temp=0;
        for (int i=0; i!=grid.size(); i++)
        {
            temp=0;
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (grid[i][j]==1) temp++;
            }
            row.push_back(temp);
        }
        for (int j=0; j!=grid[0].size(); j++)
        {
            temp=0;
            for (int i=0; i!=grid.size(); i++)
            {
                if (grid[i][j]==1) temp++;
            }
            col.push_back(temp);
        }
        long long ans=0;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (grid[i][j]==1)
                {
                    ans+=(row[i]-1)*(col[j]-1);
                }
            }
        }
        return ans;
    }
};