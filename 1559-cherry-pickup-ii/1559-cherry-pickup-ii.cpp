class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
        int w = g[0].size();
        vector<vector<vector<int>>> arr(g.size(), vector<vector<int>> (w, vector<int> (w, 0)));
        arr[0][0][w-1] += g[0][0] + g[0][w-1];
        for (int r=1; r<g.size(); r++)
        {
            for (int i=0; i<min(r+1, w); i++)
            {
                for (int j=max(0, w-1-r); j<w; j++)
                {
                    arr[r][i][j] =                              arr[r-1][i][j];
                    if (j>0)   arr[r][i][j] = max(arr[r][i][j], arr[r-1][i][j-1]);
                    if (j+1<w) arr[r][i][j] = max(arr[r][i][j], arr[r-1][i][j+1]);
                    if (i>0)
                    {
                        arr[r][i][j] =            max(arr[r][i][j], arr[r-1][i-1][j]);
                        if (j>0) arr[r][i][j] =   max(arr[r][i][j], arr[r-1][i-1][j-1]);
                        if (j+1<w) arr[r][i][j] = max(arr[r][i][j], arr[r-1][i-1][j+1]);
                    }
                    if (i+1<w)
                    {
                        arr[r][i][j] =            max(arr[r][i][j], arr[r-1][i+1][j]);
                        if (j>0) arr[r][i][j] =   max(arr[r][i][j], arr[r-1][i+1][j-1]);
                        if (j+1<w) arr[r][i][j] = max(arr[r][i][j], arr[r-1][i+1][j+1]);
                    }
                    arr[r][i][j] += g[r][i];
                    if (i!=j) arr[r][i][j] += g[r][j];
                }
            }
        }
        int ans = 0;
        for (int i=0; i!=w; i++)
        {
            for (int j=0; j!=w; j++)
            {
                ans = max(ans, arr[g.size()-1][i][j]);
            }
        }
        return ans;
    }
};