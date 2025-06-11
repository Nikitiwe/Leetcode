class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        vector<vector<long>> arr(g.size() + 1, vector<long>(g[0].size() + 1, 0));
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                arr[i+1][j+1] += arr[i+1][j];
                arr[i+1][j+1] += arr[i][j+1];
                arr[i+1][j+1] -= arr[i][j];
                arr[i+1][j+1] += g[i][j];
            }
        }
        long t = arr[g.size()][g[0].size()];
        if (t % 2 == 1) return 0;
        t /= 2;
        for (int i=0; i!=g.size(); i++)
        {
            if (arr[i][g[0].size()] == t) return 1;
        }
        for (int j=0; j!=g[0].size(); j++)
        {
            if (arr[g.size()][j] == t) return 1;
        }
        return 0;
    }
};