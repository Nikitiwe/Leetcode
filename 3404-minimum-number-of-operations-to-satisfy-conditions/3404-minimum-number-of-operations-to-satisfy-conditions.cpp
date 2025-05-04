class Solution {
public:
    int minimumOperations(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> arr(m, vector<int>(10, 0));
        for (int i=m-1; i>=0; i--)
        {
            for (int j = 0; j<10; j++)
            {
                for (int a = 0; a<n; a++) if (g[a][i] != j) arr[i][j]++;
            }
        }
        for (int i=m-2; i>=0; i--)
        {
            for (int j = 0; j<10; j++)
            {
                int add = 1000000000;
                for (int a = 0; a<10; a++)
                {
                    if (a != j)
                    {
                        add = min(add, arr[i+1][a]);
                    }
                }
                arr[i][j] += add;
            }
        }
        int ans = 1000000000;
        for (int j = 0; j<10; j++) ans = min(ans, arr[0][j]);
        return ans;
    }
};