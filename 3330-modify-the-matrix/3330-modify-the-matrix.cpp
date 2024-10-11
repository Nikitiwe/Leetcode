class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& m) {
        for (int i=0; i!=m[0].size(); i++)
        {
            int t=-2;
            for (int j=0; j!=m.size(); j++)
            {
                t=max(t, m[j][i]);
            }
            for (int j=0; j!=m.size(); j++)
            {
                if (m[j][i]==-1) m[j][i]=t;
            }
        }
        return m;
    }
};