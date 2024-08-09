class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        if (grid[0].size()==1) return 0;
        else if (grid[0].size()==2) return min(grid[0][1], grid[1][0]);
        long sumb=0, sumu=0, ans, temp;
        for (int i=0; i!=grid[0].size()-1; i++)
        {
            sumb+=grid[1][i];
        }
        temp=max(sumu, sumb);
        ans=temp;
        for (int i=grid[0].size()-1; i>0; i--)
        {
            sumu+=grid[0][i];
            sumb-=grid[1][i-1];
            temp=max(sumu, sumb);
            if (temp<ans) ans=temp;
            else break;
        }
        return ans;
    }
};