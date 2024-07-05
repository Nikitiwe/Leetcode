class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0, isit;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid.size(); j++)
            {
                isit=1;
                for (int k=0; k!=grid.size(); k++)
                {
                    if (grid[i][k]!=grid[k][j]) {isit=0; break;}
                }
                if (isit==1) ans++;
            }
        }
        return ans;
    }
};