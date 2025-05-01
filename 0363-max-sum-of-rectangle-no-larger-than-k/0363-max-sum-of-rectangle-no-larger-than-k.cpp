class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& g, int k) {
        int ans = -10000000;
        vector<vector<int>> arr(g.size()+1, vector<int>(g[0].size()+1, 0));
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                arr[i+1][j+1] += g[i][j];
                arr[i+1][j+1] += arr[i+1][j] + arr[i][j+1] - arr[i][j];
            }
        }
        for (int i=0; i!=arr.size(); i++)
        {
            for (int j=0; j!=arr[0].size(); j++)
            {
                for (int a=0; a<i; a++)
                {
                    for (int b=0; b<j; b++)
                    {
                        int t = arr[i][j] - arr[i][b] - arr[a][j] + arr[a][b];
                        if (t <= k) ans = max(ans, t);
                    }
                }
            }
        }
        return ans;
    }
};