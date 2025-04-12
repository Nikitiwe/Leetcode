class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& g, int k) {
        int ans = 0;
        vector<vector<int>> arr(g.size()+1, vector<int> (g[0].size()+1, 0));
        for (int i=1; i!=arr.size(); i++)
        {
            for (int j=1; j!=arr[0].size(); j++)
            {
                arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
                arr[i][j] += g[i-1][j-1];
            }
        }
        for (int i=1; i!=arr.size(); i++)
        {
            for (int j=1; j!=arr[0].size(); j++)
            {
                for (int a=1; a<=i; a++)
                {
                    for (int b=1; b<=j; b++)
                    {
                        if (arr[i][j] + arr[a-1][b-1] - arr[i][b-1] - arr[a-1][j] == k) ans++;
                    }
                }
            }
        }
        return ans;
    }
};