class Solution {
public:
    int longestCommonSubsequence(string s, string w) {
        vector<vector<int>> arr(s.size(), vector<int>(w.size(), 0));
        int ans = 0;
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=0; j!=w.size(); j++)
            {
                if (i > 0 && j > 0)
                {
                    if (s[i] == w[j]) arr[i][j] = arr[i-1][j-1] + 1;
                    arr[i][j] = max(arr[i][j], arr[i-1][j]);
                    arr[i][j] = max(arr[i][j], arr[i][j-1]);
                    ans = max(ans, arr[i][j]);
                }
                else if (i == 0 && j > 0)
                {
                    if (s[i] == w[j]) arr[i][j] = 1;
                    arr[i][j] = max(arr[i][j], arr[i][j-1]);
                    ans = max(ans, arr[i][j]);
                }
                else if (i > 0 && j == 0)
                {
                    if (s[i] == w[j]) arr[i][j] = 1;
                    arr[i][j] = max(arr[i][j], arr[i-1][j]);
                    ans = max(ans, arr[i][j]);
                }
                else
                {
                    if (s[i] == w[j]) arr[i][j] = 1;
                    ans = max(ans, arr[i][j]);
                }
            }
        }
        return ans;
    }
};