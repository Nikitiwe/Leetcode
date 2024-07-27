class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int l=0, r=matrix.size()-1;
        if (matrix[0][0]>t) return 0;
        while (l<r-1)
        {
            if (matrix[l][matrix[0].size()-1]>=t)
            {
                r=l;
                l/=2;
            }
            else
            {
                l=(l+r)/2;
            }
        }
        if (l+1<matrix.size()&&matrix[l][matrix[0].size()-1]<t) l++;
        int a=0, b=matrix[0].size()-1;
        while (a<b-1)
        {
            if (matrix[l][a]>=t)
            {
                b=a;
                a/=2;
            }
            else
            {
                a=(a+b)/2;
            }
        }
        if (matrix[l][a]==t||matrix[l][b]==t) return 1;
        else return 0;
    }
};