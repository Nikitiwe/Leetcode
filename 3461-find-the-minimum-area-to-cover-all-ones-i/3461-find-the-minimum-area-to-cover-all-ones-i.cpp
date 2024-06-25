class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int maxX, minX, maxY=0, minY=0;
        for (int i=0; i!=grid.size(); i++)
        {
            auto it=find(grid[i].begin(), grid[i].end(), 1);
            if (it!=grid[i].end()) {minX=i; break;}
        }
        for (int i=grid.size()-1; i>=0; i--)
        {
            auto it=find(grid[i].begin(), grid[i].end(), 1);
            if (it!=grid[i].end()) {maxX=i; break;}
        }
        for (int i=0; i!=grid[0].size(); i++)
        {
            for (int j=0; j!=grid.size(); j++)
            {
                if (grid[j][i]==1) {maxY=i; break;}
            }
        }
        for (int i=grid[0].size()-1; i>=0; i--)
        {
            for (int j=0; j!=grid.size(); j++)
            {
                if (grid[j][i]==1) {minY=i; break;}
            }
        }
        return (maxX-minX+1)*(maxY-minY+1);
    }
};