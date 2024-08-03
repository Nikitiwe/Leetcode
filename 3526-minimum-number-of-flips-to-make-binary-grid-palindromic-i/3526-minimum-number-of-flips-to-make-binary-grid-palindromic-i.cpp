class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans1=0, ans2=0;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size()/2; j++)
            {
                if (grid[i][j]!=grid[i][grid[0].size()-1-j]) ans1++;
            }
        }
        for (int j=0; j!=grid[0].size(); j++)
        {
            for (int i=0; i!=grid.size()/2; i++)
            {
                if (grid[i][j]!=grid[grid.size()-1-i][j]) ans2++;
            }
        }
        return min(ans1, ans2);
    }
};