class NeighborSum {
public:
    unordered_map<int, int> as, ds;
    NeighborSum(vector<vector<int>>& g) {
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[i].size(); j++)
            {
                int ans = 0;
                if (i>0) ans += g[i-1][j];
                if (j > 0) ans += g[i][j-1];
                if (i<g.size() - 1) ans += g[i+1][j];
                if (j<g[0].size() - 1) ans += g[i][j+1];
                as[g[i][j]] = ans;
                ans = 0;
                if (i>0 && j > 0) ans += g[i-1][j-1];
                if (i<g.size() - 1 && j > 0) ans += g[i+1][j-1];
                if (i>0 && j<g[0].size() - 1) ans += g[i-1][j+1];
                if (i<g.size() - 1 && j<g[0].size() - 1) ans += g[i+1][j+1];
                ds[g[i][j]] = ans;
            }
        }
    }
    
    int adjacentSum(int value) {
        return as[value];
    }
    
    int diagonalSum(int value) {
        return ds[value];
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */