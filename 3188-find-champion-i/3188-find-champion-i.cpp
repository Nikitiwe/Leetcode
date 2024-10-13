class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        vector<bool> arr(grid.size(), 1);
        for (int i=0; i!=grid.size(); i++)
        {
            if (arr[i]==1)
            {
                int sum=0;
                for (int j=0; j!=grid[0].size(); j++)
                {
                    if (grid[i][j]==1)
                    {
                        sum++;
                        arr[j]=0;
                    }
                }
                if (sum==grid[0].size()-1) return i;
            }
        }
        return -1;
    }
};