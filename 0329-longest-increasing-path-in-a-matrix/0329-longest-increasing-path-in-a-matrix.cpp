class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        vector<int> row(matrix[0].size(), 0), val;
        for (int i=0; i!=matrix.size(); i++)
        {
            ans.push_back(row);
        }
        for(int i=0; i!=matrix.size(); i++)
        {
            for(int j=0; j!=matrix[0].size(); j++)
            {
                val.push_back(matrix[i][j]);
            }
        }
        sort(val.begin(), val.end());
        int temp;
        for (int k=val.size()-1; k>=0; k--)
        {
            for(int i=0; i!=matrix.size(); i++)
            {
                for(int j=0; j!=matrix[0].size(); j++)
                {
                    if (matrix[i][j]==val[k])
                    {
                        temp=0;
                        if(i>0&&matrix[i-1][j]>matrix[i][j]) temp=max(temp, ans[i-1][j]);
                        if(j>0&&matrix[i][j-1]>matrix[i][j]) temp=max(temp, ans[i][j-1]);
                        if(i<matrix.size()-1&&matrix[i+1][j]>matrix[i][j]) temp=max(temp, ans[i+1][j]);
                        if(j<matrix[0].size()-1&&matrix[i][j+1]>matrix[i][j]) temp=max(temp, ans[i][j+1]);
                        ans[i][j]=temp+1;
                    }
                }
            }
        }
        temp=0;
        for(int i=0; i!=matrix.size(); i++)
        {
            for(int j=0; j!=matrix[0].size(); j++)
            {
                temp=max(temp, ans[i][j]);
            }
        }
        return temp;
    }
};