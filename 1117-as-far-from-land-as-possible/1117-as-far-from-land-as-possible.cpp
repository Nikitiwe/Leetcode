class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans=0, n=grid.size();
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (j>0&&grid[i][j-1]>0&&grid[i][j]!=1) grid[i][j]=grid[i][j-1]+1;
                if (i>0&&grid[i-1][j]>0&&grid[i][j]!=1&&grid[i][j]!=0) grid[i][j]=min(grid[i][j], grid[i-1][j]+1);
                else if (i>0&&grid[i-1][j]>0&&grid[i][j]!=1&&grid[i][j]==0) grid[i][j]=grid[i-1][j]+1;
            }
        }
        for (int i=n-1; i>=0; i--)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (grid[i][j]!=0&&grid[i][j]!=1)
                {
                    if (j<n-1&&grid[i][j+1]+1<grid[i][j]) grid[i][j]=grid[i][j+1]+1;
                    if (i<n-1&&grid[i+1][j]+1<grid[i][j]) grid[i][j]=min(grid[i][j], grid[i+1][j]+1);
                    ans=max(ans, grid[i][j]);
                }
                if (grid[i][j]==0)
                {
                    if (j<n-1&&grid[i][j+1]>0) grid[i][j]=grid[i][j+1]+1;
                    if (i<n-1&&grid[i+1][j]>0&&grid[i][j]!=1&&grid[i][j]!=0) grid[i][j]=min(grid[i][j], grid[i+1][j]+1);
                    else if (i<n-1&&grid[i+1][j]>0&&grid[i][j]!=1&&grid[i][j]==0) grid[i][j]=grid[i+1][j]+1;
                    ans=max(ans, grid[i][j]);
                }
            }
        }
        if (ans<=1) return -1;
        else return ans-1;
    }
};