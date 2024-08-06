class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
        for (int i=1; i<mat.size(); i++)
        {
            for (int j=1; j<mat[0].size(); j++)
            {
                if (matrix[i-1][j-1]=='1') mat[i][j]=1;
            }
        }
        for (int i=1; i<mat.size(); i++)
        {
            for (int j=1; j<mat[0].size(); j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
        for (int i=1; i<mat.size(); i++)
        {
            for (int j=1; j<mat[0].size(); j++)
            {
                mat[i][j]+=mat[i-1][j];
            }
        }
        int ans=0;
        for (int i=1; i<mat.size(); i++)
        {
            for (int j=1; j<mat[0].size(); j++)
            {
                for (int k=ans+1; k+i-1<mat.size()&&k+j-1<mat[0].size(); k++)
                {
                    if (k*k==mat[k+i-1][k+j-1]+mat[i-1][j-1]-mat[i-1][k+j-1]-mat[k+i-1][j-1]) ans=k;
                    else break;
                }
            }
        }
        return ans*ans;
    }
};