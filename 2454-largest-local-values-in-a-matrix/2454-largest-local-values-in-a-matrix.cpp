class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        vector<int> str;
        for (int i=1; i!=grid[0].size()-1; i++)
        {
            str.clear();
            for (int j=1; j!=grid[0].size()-1; j++)
            {
                str.push_back(
                max(max(max(max(grid[i-1][j-1], grid[i][j-1]), max(grid[i+1][j-1], grid[i-1][j])),
                max(max(grid[i][j], grid[i+1][j]), max(grid[i-1][j+1], grid[i][j+1]))), grid[i+1][j+1]));
            }
            ans.push_back(str);
        }
        return ans;
    }
};