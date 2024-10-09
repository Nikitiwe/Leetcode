class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        for (int i=0; i<=1; i++)
        {
            for (int j=0; j<=1; j++)
            {
                int t=0;
                if (g[i][j]=='W') t++;
                if (g[i+1][j]=='W') t++;
                if (g[i][j+1]=='W') t++;
                if (g[i+1][j+1]=='W') t++;
                if (t!=2) return 1;
            }
        }
        return 0;
    }
};