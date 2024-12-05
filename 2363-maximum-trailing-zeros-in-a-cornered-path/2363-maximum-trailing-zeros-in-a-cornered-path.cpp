class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size();
        vector<vector<int>> art(g.size()+1, vector<int> (g[0].size()+1, 0)), arf=art;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                while (g[i][j]%2==0)
                {
                    art[i+1][j+1]++;
                    g[i][j]/=2;
                }
                art[i+1][j+1]+=art[i+1][j]+art[i][j+1]-art[i][j];
                while (g[i][j]%5==0)
                {
                    arf[i+1][j+1]++;
                    g[i][j]/=5;
                }
                arf[i+1][j+1]+=arf[i+1][j]+arf[i][j+1]-arf[i][j];
            }
        }
        int ans=0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++) // право вниз
            {
                int tt=art[m][j+1]+art[i][j]-art[i][j+1]-art[m][j], ff=arf[m][j+1]+arf[i][j]-arf[i][j+1]-arf[m][j];
                tt+=art[i+1][n]+art[i][j+1]-art[i+1][j+1]-art[i][n];
                ff+=arf[i+1][n]+arf[i][j+1]-arf[i+1][j+1]-arf[i][n];
                ans=max(ans, min(tt, ff));
            }
            for (int j=0; j!=g[0].size(); j++) // право вверх
            {
                int tt=art[i+1][j+1]+art[0][j]-art[i+1][j]-art[0][j+1], ff=arf[i+1][j+1]+arf[0][j]-arf[i+1][j]-arf[0][j+1];
                tt+=art[i+1][n]+art[i][j+1]-art[i+1][j+1]-art[i][n];
                ff+=arf[i+1][n]+arf[i][j+1]-arf[i+1][j+1]-arf[i][n];
                ans=max(ans, min(tt, ff));
            }
            for (int j=0; j!=g[0].size(); j++) // лево вверх
            {
                int tt=art[i+1][j+1]+art[0][j]-art[i+1][j]-art[0][j+1], ff=arf[i+1][j+1]+arf[0][j]-arf[i+1][j]-arf[0][j+1];
                tt+=art[i+1][j]+art[i][0]-art[i+1][0]-art[i][j];
                ff+=arf[i+1][j]+arf[i][0]-arf[i+1][0]-arf[i][j];
                ans=max(ans, min(tt, ff));
            }
            for (int j=0; j!=g[0].size(); j++) // лево вниз
            {
                int tt=art[m][j+1]+art[i][j]-art[i][j+1]-art[m][j], ff=arf[m][j+1]+arf[i][j]-arf[i][j+1]-arf[m][j];
                tt+=art[i+1][j]+art[i][0]-art[i+1][0]-art[i][j];
                ff+=arf[i+1][j]+arf[i][0]-arf[i+1][0]-arf[i][j];
                ans=max(ans, min(tt, ff));
            }
        }
        return ans;
    }
};