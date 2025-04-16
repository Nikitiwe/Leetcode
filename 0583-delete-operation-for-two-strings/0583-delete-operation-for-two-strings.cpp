class Solution {
public:
    int minDistance(string s, string w) {
        vector<vector<int>> arr(s.size() + 1, vector<int>(w.size() + 1, 0));
        for (int i=1; i<=s.size(); i++)
        {
            for (int j=1; j<=w.size(); j++)
            {
                if (s[i-1] == w[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
                else arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
            }
        }
        return s.size() + w.size() - 2*arr[s.size()][w.size()];
    }
};