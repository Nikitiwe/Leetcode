class Solution {
public:
    int kthLargestValue(vector<vector<int>>& g, int k) {
        vector<int> arr;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (i > 0) g[i][j] ^= g[i-1][j];
                if (j > 0) g[i][j] ^= g[i][j-1];
                if (i > 0 && j>0) g[i][j] ^= g[i-1][j-1];
                arr.push_back(g[i][j]);
            }
        }
        sort(arr.rbegin(), arr.rend());
        return arr[k-1];
    }
};