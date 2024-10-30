class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& m, int r, int c) {
        int p=r*c;
        if (p!=m.size()*m[0].size()) return m;
        vector<vector<int>> ans(r, vector<int> (c, 0));
        for (int i=0; i!=p; i++)
        {
            ans[i/c][i%c]=m[i/m[0].size()][i%m[0].size()];
        }
        return ans;
    }
};