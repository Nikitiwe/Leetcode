class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid;
        vector<int> row(n, 0);
        int ans=0;
        for (int i=0; i!=m; i++) grid.push_back(row);
        for (int i=0; i!=walls.size(); i++)
        {
            grid[walls[i][0]][walls[i][1]]=3;
        }
        for (int k=0; k!=guards.size(); k++)
        {
            grid[guards[k][0]][guards[k][1]]=2;
        }
        for (int k=0; k!=guards.size(); k++)
        {
            for (int i=1; guards[k][0]+i<m; i++)
            {
                if (grid[guards[k][0]+i][guards[k][1]]>1) break;
                else grid[guards[k][0]+i][guards[k][1]]=1;
            }
            for (int i=1; guards[k][0]-i>=0; i++)
            {
                if (grid[guards[k][0]-i][guards[k][1]]>1) break;
                else grid[guards[k][0]-i][guards[k][1]]=1;
            }
            for (int i=1; guards[k][1]+i<n; i++)
            {
                if (grid[guards[k][0]][guards[k][1]+i]>1) break;
                else grid[guards[k][0]][guards[k][1]+i]=1;
            }
            for (int i=1; guards[k][1]-i>=0; i++)
            {
                if (grid[guards[k][0]][guards[k][1]-i]>1) break;
                else grid[guards[k][0]][guards[k][1]-i]=1;
            }
        }
        for (int i=0; i!=m; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (grid[i][j]==0) ans++;
            }
        }
        return ans;
    }
};