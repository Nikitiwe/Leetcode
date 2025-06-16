class Solution {
public:
    int findRotateSteps(string s, string k) {
        int n = s.size();
        vector<vector<int>> arr(k.size(), vector<int>(n, 1e8));
        for (int j=0; j<n; j++)
        {
            if (s[j] == k[0])
            {
                arr[0][j] = 1 + min(j, n - j);
            }
        }
        for (int i=1; i!=k.size(); i++)
        {
            for (int j=0; j<n; j++)
            {
                if (s[j] == k[i])
                {
                    for (int p = 0; p<n; p++)
                    {
                        if (arr[i-1][p] < 1e8)
                        {
                            arr[i][j] = min(arr[i][j], arr[i-1][p] + 1 + min(abs(p-j), n - abs(p-j)));
                        }
                    }
                }
            }
        }
        int ans = 1e8;
        for (int j=0; j<n; j++) ans = min(ans, arr[k.size()-1][j]);
        return ans;
    }
};