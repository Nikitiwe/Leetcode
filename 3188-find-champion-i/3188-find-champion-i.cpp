class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for (int i=0; i!=grid.size(); i++)
        {
            int sum=0;
            for (int j=0; j!=grid[0].size(); j++)
            {
                sum+=grid[i][j];
            }
            if (sum==grid[0].size()-1) return i;
        }
        return -1;
    }
};