class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int k) {
        int ll = 0, rr = g[0].size()-1;
        for (int i=0; i!=g.size(); i++)
        {
            int l = ll, r = rr, m;
            while (l <= r)
            {
                m = (l+r)/2;
                if (g[i][m] == k) return 1;
                else if (g[i][m] > k)
                {
                    rr = m - 1;
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
        }
        return 0;
    }
};