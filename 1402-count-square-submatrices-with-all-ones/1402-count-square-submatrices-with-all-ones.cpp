class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int ans=0;

        for (int i=0; i!=m.size(); i++) ans+=m[i][0];
        for (int j=1; j<m[0].size(); j++) ans+=m[0][j];

            for (int i=1; i<m.size(); i++)
            {
                for (int j=1; j<m[0].size(); j++)
                {
                    if (m[i][j]>0)
                    {
                        m[i][j]=min({m[i-1][j-1], m[i][j-1], m[i-1][j]})+1;
                        ans+=m[i][j];
                    }
                }
            }

        return ans;
    }
};