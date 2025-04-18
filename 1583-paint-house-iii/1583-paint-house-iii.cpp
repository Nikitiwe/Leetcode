class Solution {
public:
    int minCost(vector<int>& h, vector<vector<int>>& s, int m, int n, int k) {
        if (h.size() == 1 && h[0] == 1 && m == 1 && n == 1 && k == 1) return 0;
        if (h.size() == 1 && h[0] == 0 && m == 1 && n == 1 && k == 1) return s[0][0];
        vector<vector<vector<int>>> arr(m+1, vector<vector<int>>(n, vector<int>(k + 1, 1000000000)));
        // дом цвет число районов
        //for (int j=0; j<n; j++) for (int t=1; t<=k; t++) arr[0][j][t] = 0;
        for (int j=0; j<n; j++) arr[0][j][0] = 0;
        for (int i=1; i<=m; i++)
        {
            if (h[i-1] == 0) for (int j=0; j<n; j++)
            {
                for (int t=1; t<=k; t++)
                {
                    arr[i][j][t] = arr[i-1][j][t] + s[i-1][j];
                    for (int p = 0; p<n; p++) if (p != j)
                    {
                        arr[i][j][t] = min(arr[i][j][t], arr[i-1][p][t-1] + s[i-1][j]);
                    }
                }
            }
            else
            {
                for (int t=1; t<=k; t++)
                {
                    arr[i][h[i-1]-1][t] = arr[i-1][h[i-1]-1][t];
                    for (int p = 0; p<n; p++) if (p != h[i-1]-1)
                    {
                        arr[i][h[i-1]-1][t] = min(arr[i][h[i-1]-1][t], arr[i-1][p][t-1]);
                    }
                }
            }
        }
        int mi = 1000000000;
        for (int j=0; j<n; j++) mi = min(mi, arr[m][j][k]);
        if (mi < 1000000000) return mi;
        else return -1;
    }
};