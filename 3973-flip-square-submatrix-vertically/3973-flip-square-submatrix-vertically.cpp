class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& g, int x, int y, int k) {
        for (int i=0; i<k/2; i++)
        {
            for (int j=y; j<y+k; j++)
            {
                swap(g[i+x][j], g[x+k-1-i][j]);
            }
        }
        return g;
    }
};