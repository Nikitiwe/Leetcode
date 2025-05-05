class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& g, int kk) {
        vector<vector<vector<int>>> arr(g.size(), vector<vector<int>>(g[0].size(), vector<int>(16, 0)));
        arr[0][0][g[0][0]] = 1;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (i > 0) for (int k = 0; k<16; k++)
                {
                    arr[i][j][k] += arr[i-1][j][k^g[i][j]];
                }
                if (j > 0) for (int k = 0; k<16; k++)
                {
                    arr[i][j][k] += arr[i][j-1][k^g[i][j]];
                }
                for (int k = 0; k<16; k++) arr[i][j][k] %= 1000000007;
            }
        }
        return arr[g.size() - 1][g[0].size() - 1][kk];
    }
};