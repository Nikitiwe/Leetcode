class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        vector<int> arr(g[0].size(), 0);
        for (int i=0; i!=g.size(); i++)
        {
            arr[0]++;
            for (int j=1; j<g[0].size(); j++)
            {
                if (g[i][0] == 1) arr[j] += g[i][j];
                else arr[j] += (1 - g[i][j]);
            }
        }
        int ans = 0, d = 1;
        for (int j = arr.size()-1; j>=0; j--)
        {
            ans += d*max((int)arr[j], (int)g.size() - arr[j]);
            d *= 2;
        }
        return ans;
    }
};