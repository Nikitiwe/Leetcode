class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for (int i=0; i<mat.size(); i++)
        {
            if (i%2==0)
            {
                for (int j=0; j!=mat[0].size(); j++)
                {
                    if (mat[i][j]!=mat[i][(j+k)%mat[0].size()]) return 0;
                }
            }
            else
            {
                for (int j=0; j!=mat[0].size(); j++)
                {
                    if (mat[i][j]!=mat[i][(j+50*mat[0].size()-k)%mat[0].size()]) return 0;
                }
            }
        }
        return 1;
    }
};