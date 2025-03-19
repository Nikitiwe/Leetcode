class Solution {
public:
    int largestOverlap(vector<vector<int>>& s, vector<vector<int>>& w) {
        int ans = 0;
        int n = s.size();
        for (int i = -n+1; i<n; i++)
        {
            for (int j = -n+1; j<n; j++)
            {
                int t = 0;
                for (int a = 0; a!=n; a++)
                {
                    for (int b = 0; b!=n; b++)
                    {
                        if (w[a][b] == 1)
                        {
                            if (a+i>=0 && a+i<n && b+j>=0 && b+j<n && s[a+i][b+j] == 1) t++;
                        }
                    }
                }
                ans = max(ans, t);
            }
        }
        return ans;
    }
};