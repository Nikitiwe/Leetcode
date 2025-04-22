class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& d) {
        int ans = 0;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for (int i=0; i!=d.size(); i++) arr[d[i][0]][d[i][1]] = 1;
        for (int i=0; i!=a.size(); i++)
        {
            bool isit = 1;
            for (int x = a[i][0]; x <= a[i][2]; x++)
            {
                for (int y = a[i][1]; y <= a[i][3]; y++)
                {
                    if (arr[x][y] == 0) isit = 0;
                }
            }
            if (isit == 1) ans++;
        }
        return ans;
    }
};