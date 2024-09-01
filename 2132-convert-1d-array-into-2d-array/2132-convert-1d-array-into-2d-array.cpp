class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& og, int m, int n) {
        if (m*n!=og.size()) return {};
        vector<vector<int>> ans (m, vector<int> (n, 0));
        int t;
        for (int i=0; i!=m; i++)
        {
            t=i*n;
            for (int j=0; j!=n; j++)
            {
                ans[i][j]=og[t+j];
            }
        }
        return ans;
    }
};