class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t=1, x=0, y=0, nn=n*n;
        vector<vector<int>> ans(n, vector<int> (n, 0));
        while (t<=nn)
        {
            while (1)
            {
                if (ans[x][y]==0)
                {
                    ans[x][y]=t;
                    t++;
                }
                if (y+1<n&&ans[x][y+1]==0) y++;
                else break;
            }
            while (1)
            {
                if (ans[x][y]==0)
                {
                    ans[x][y]=t;
                    t++;
                }
                if (x+1<n&&ans[x+1][y]==0) x++;
                else break;
            }
            while (1)
            {
                if (ans[x][y]==0)
                {
                    ans[x][y]=t;
                    t++;
                }
                if (y-1>=0&&ans[x][y-1]==0) y--;
                else break;
            }
            while (1)
            {
                if (ans[x][y]==0)
                {
                    ans[x][y]=t;
                    t++;
                }
                if (x-1>=0&&ans[x-1][y]==0) x--;
                else break;
            }
        }
        return ans;
    }
};