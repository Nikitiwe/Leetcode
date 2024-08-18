class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<long>>> arr(grid.size(), vector<vector<long>> (grid[0].size(), vector<long> (k, 0)));
        arr[0][0][grid[0][0]%k]++;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (i<grid.size()-1) for (int a=0; a!=k; a++)
                {
                    arr[i+1][j][ (a+grid[i+1][j])%k ]+=arr[i][j][a];
                    arr[i+1][j][ (a+grid[i+1][j])%k ]%=1000000007;
                }
                if (j<grid[0].size()-1) for (int a=0; a!=k; a++)
                {
                    arr[i][j+1][ (a+grid[i][j+1])%k ]+=arr[i][j][a];
                    arr[i][j+1][ (a+grid[i][j+1])%k ]%=1000000007;
                }
            }
        }
        return arr[grid.size()-1][grid[0].size()-1][0];
    }
};