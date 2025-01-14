class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        for (int i=0; i!=m.size(); i++)
        {
            int t=m[i][0], d=1, j=0;
            while (i+d<m.size()&&j+d<m[0].size())
            {
                if (m[i+d][j+d]!=t) return 0;
                d++;
            }
        }
        for (int j=0; j!=m[0].size(); j++)
        {
            int t=m[0][j], d=1, i=0;
            while (i+d<m.size()&&j+d<m[0].size())
            {
                if (m[i+d][j+d]!=t) return 0;
                d++;
            }
        }
        return 1;
    }
};