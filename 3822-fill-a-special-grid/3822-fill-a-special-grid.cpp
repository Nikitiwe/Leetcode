class Solution {
public:
    void f(vector<vector<int>> & ans, int a, int u, int d, int l, int r)
    {
        if (r - l == 1) ans[u][l] = a;
        else
        {
            int add = (r-l)*(d-u)/4;
            f(ans, a,           u, (u+d)/2, (r+l)/2, r);
            f(ans, a + add,     (u+d)/2, d, (r+l)/2, r);
            f(ans, a + 2*add,   (u+d)/2, d, l, (r+l)/2);
            f(ans, a + 3*add,   u, (u+d)/2, l, (r+l)/2);
        }
    }

    vector<vector<int>> specialGrid(int n) {
        int k = 1;
        for (int i=0; i<n; i++) k *= 2;
        vector<vector<int>> ans(k, vector<int>(k, 0));
        f(ans, 0, 0, k, 0, k);
        return ans;
    }
};