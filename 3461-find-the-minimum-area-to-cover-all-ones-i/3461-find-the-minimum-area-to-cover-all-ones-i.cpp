class Solution {
public:
    int minimumArea(vector<vector<int>>& g) {
        int maxX = 0, minX = g.size(), maxY = 0, minY = g[0].size();
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j] == 1)
                {
                    maxX = max(maxX, i);
                    minX = min(minX, i);
                    maxY = max(maxY, j);
                    minY = min(minY, j);
                }
            }
        }
        return (maxX-minX+1)*(maxY-minY+1);
    }
};