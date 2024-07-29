class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int m=999999, count=0;
        for (int i=0; i!=matrix.size(); i++)
        {
            for (int j=0; j!=matrix[0].size(); j++)
            {
                ans+=abs(matrix[i][j]);
                m=min(m, abs(matrix[i][j]));
                if (matrix[i][j]<0) count++;
            }
        }
        if (count%2==0) return ans;
        else return ans-m*2;
    }
};