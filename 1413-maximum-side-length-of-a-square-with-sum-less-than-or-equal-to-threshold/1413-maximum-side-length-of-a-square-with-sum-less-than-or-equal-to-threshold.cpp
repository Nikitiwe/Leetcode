class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> sum;
        vector<int> row(mat[0].size()+1, 0);
        int ans=0, temp=0;
        for (int i=0; i<=mat.size(); i++)
        {
            sum.push_back(row);
        }
        for (int i=0; i!=sum.size()-1; i++)
        {
            for (int j=0; j!=sum[0].size()-1; j++)
            {
                sum[i+1][j+1]=sum[i+1][j]+mat[i][j]+sum[i][j+1]-sum[i][j];
            }
        }
        for (int i=1; i!=sum.size(); i++)
        {
            for (int j=1; j!=sum[0].size(); j++)
            {
                for (int k=ans; k+j<sum[0].size()&&k+i<sum.size(); k++)
                {
                    temp=sum[i+k][j+k]+sum[i-1][j-1]-sum[i+k][j-1]-sum[i-1][j+k];
                    if (temp<=threshold) ans=max(ans, k+1);
                    else break;
                }
            }
        }
        return ans;
    }
};