class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> arr(grid.size(), vector<int> (grid[0].size(), 0));
        if (grid[0][0]==0) arr[0][0]=1;
        else return 0;
        int a=1;
        while (a<grid.size()&&grid[a][0]==0)
        {
            arr[a][0]=1;
            a++;
        }
        a=1;
        while (a<grid[0].size()&&grid[0][a]==0)
        {
            arr[0][a]=1;
            a++;
        }
        for (int i=1; i<grid.size(); i++)
        {
            for (int j=1; j<grid[0].size(); j++)
            {
                if (grid[i][j]==0) arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[grid.size()-1][grid[0].size()-1];
    }
};