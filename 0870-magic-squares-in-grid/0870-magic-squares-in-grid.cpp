class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size()<3||grid[0].size()<3) return 0;
        int ans=0, f, m;
        for (int i=0; i<=grid.size()-3; i++)
        {
            for (int j=0; j<=grid[0].size()-3; j++)
            {
                f=1;
                for (int k=1; k<=9; k++)
                {
                    if (grid[i][j]==k||grid[i+1][j]==k||grid[i+2][j]==k||
                        grid[i][j+1]==k||grid[i+1][j+1]==k||grid[i+2][j+1]==k||
                        grid[i][j+2]==k||grid[i+1][j+2]==k||grid[i+2][j+2]==k) continue;
                    else {f=0; break;}
                }
                if (f==1)
                {
                    if (grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=15) continue;
                    if (grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]!=15) continue;
                    if (grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=15) continue;
                    if (grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]!=15) continue;
                    if (grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=15) continue;
                    if (grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2]!=15) continue;
                    ans++;
                }
            }
        }
        return ans;
    }
};