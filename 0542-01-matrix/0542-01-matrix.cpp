class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        vector<int> row(mat[0].size(), 0);
        for (int i=0; i!=mat.size(); i++) ans.push_back(row);
        for (int i=0; i!=mat.size(); i++)
        {
            for (int j=0; j!=mat[0].size(); j++)
            {
                if (mat[i][j]==1)
                {
                    ans[i][j]=30000;
                    if (i>0) ans[i][j]=min(ans[i][j], ans[i-1][j]+1);
                    if (j>0) ans[i][j]=min(ans[i][j], ans[i][j-1]+1);
                }
            }
        }
        for (int i=mat.size()-1; i>=0; i--)
        {
            for (int j=mat[0].size()-1; j>=0; j--)
            {
                if (mat[i][j]==1)
                {
                    if (i<mat.size()-1) ans[i][j]=min(ans[i][j], ans[i+1][j]+1);
                    if (j<mat[0].size()-1) ans[i][j]=min(ans[i][j], ans[i][j+1]+1);
                }
            }
        }
        return ans;
    }
};