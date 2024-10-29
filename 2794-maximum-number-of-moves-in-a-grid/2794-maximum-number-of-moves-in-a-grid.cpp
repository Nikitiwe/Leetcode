class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int> (grid[0].size(), 0));
        int temp=0, m=0;
        for (int k=0; k<grid.size(); k++)  ans[k][0]=1;

            for (int j=1; j<grid[0].size(); j++)
            {
                for (int i=0; i<grid.size(); i++)
                {
                    if (ans[i][j-1]==1&&grid[i][j-1]<grid[i][j]) {ans[i][j]=1; temp=j;}
                    else if (i>0&&ans[i-1][j-1]==1&&grid[i-1][j-1]<grid[i][j]) {ans[i][j]=1; temp=j;}
                    else if (i<grid.size()-1&&ans[i+1][j-1]==1&&grid[i+1][j-1]<grid[i][j]) {ans[i][j]=1; temp=j;}
                }
                if (temp<j) break;
            }
            m=max(m, temp);

        return m;
    }
};