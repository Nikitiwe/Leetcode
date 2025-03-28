class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& g) {
        for (int k = g.size()-1; k > -(int)g[0].size(); k--)
        {
            vector<int> t;
            for (int i = 0; i<g[0].size(); i++)
            {
                if ( k + i >= 0 )
                {
                    if (k + i >= g.size()) break;
                    t.push_back(g[k+i][i]);
                }
            }
            sort(t.begin(), t.end());
            int j = 0;
            for (int i = 0; i<g[0].size(); i++)
            {
                if ( k + i >= 0 )
                {
                    if (k + i >= g.size()) break;
                    g[k+i][i] = t[j];
                    j++;
                }
            }
        }
        return g;
    }
};