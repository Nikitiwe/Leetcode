class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int x;
        for (int i=0; i!=grid[0].size(); i++)
        {
            x=i;
            for (int j=0; j<=grid.size()-1; j++)
            {
                if (x==0&&grid[j][x]==-1) {ans.push_back(-1); break;}
                else if (x==grid[0].size()-1&&grid[j][x]==1) {ans.push_back(-1); break;}
                else if (grid[j][x]==1&&grid[j][x+1]==-1) {ans.push_back(-1); break;}
                else if (grid[j][x]==-1&&grid[j][x-1]==1) {ans.push_back(-1); break;}
                else if (grid[j][x]==1&&grid[j][x+1]==1) {x++;}
                else if (grid[j][x]==-1&&grid[j][x-1]==-1) {x--;}
                if (j==grid.size()-1) ans.push_back(x);
            }
        }
        return ans;
    }
};