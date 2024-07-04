class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans;
        vector<int> row(colSum.size(), 0);
        for (int i=0; i!=rowSum.size(); i++) ans.push_back(row);
        int temp;
        for (int i=0; i!=rowSum.size(); i++)
        {
            for (int j=0; j!=colSum.size(); j++)
            {
                while (rowSum[i]>0&&colSum[j]>0)
                {
                    temp=min(rowSum[i], colSum[j]);
                    ans[i][j]=ans[i][j]+temp;
                    rowSum[i]-=temp;
                    colSum[j]-=temp;
                }
            }
        }
        return ans;
    }
};