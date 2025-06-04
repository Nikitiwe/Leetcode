class Solution {
public:
    int maximumAmount(vector<vector<int>>& c) {
        if (c.size() == 1 && c[0].size() == 1) return c[0][0] >= 0 ? c[0][0] : 0;
        vector<vector<vector<int>>> arr(c.size(), vector<vector<int>>(c[0].size(), vector<int>(3, -1e8)));
        // высота + ширина + слой
        arr[0][0][0] = c[0][0];
        arr[0][0][1] = 0;
        arr[0][0][2] = 0;
        for (int k=0; k<3; k++)
        {
            for (int i=0; i!=c.size(); i++)
            {
                for (int j=0; j!=c[0].size(); j++)
                {
                    if (i > 0) arr[i][j][k] = arr[i-1][j][k] + c[i][j];
                    if (j > 0) arr[i][j][k] = max(arr[i][j][k], arr[i][j-1][k] + c[i][j]);
                    if (k > 0 && i > 0) arr[i][j][k] = max(arr[i][j][k], arr[i-1][j][k-1]);
                    if (k > 0 && j > 0) arr[i][j][k] = max(arr[i][j][k], arr[i][j-1][k-1]);
                }
            }
        }
        //return arr[c.size()-1][c[0].size()-1][2];
        return max({arr[c.size()-1][c[0].size()-1][0], arr[c.size()-1][c[0].size()-1][1], arr[c.size()-1][c[0].size()-1][2]});
    }
};