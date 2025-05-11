class Solution {
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        vector<pair<int, int>> nums;
        for (int i=0; i!=s.size(); i++)
        {
            int a = 0, b = 0;
            for (int j=0; j!=s[i].size(); j++)
            {
                if (s[i][j] == '0') a++;
                else b++;
            }
            if (a <= m && b <= n) nums.push_back({a, b});
        }
        vector<vector<int>> arr(m+1, vector<int>(n+1, 0));
        arr[0][0] = 1;
        for (int k = 0; k<nums.size(); k++)
        {
            for (int i=m; i>=0; i--)
            {
                for (int j=n; j>=0; j--)
                {
                    if (arr[i][j] > 0)
                    {
                        if (i + nums[k].first <= m && j + nums[k].second <= n)
                        {
                            arr[i + nums[k].first][j + nums[k].second] = max(arr[i + nums[k].first][j + nums[k].second], arr[i][j] + 1);
                        }
                    }
                }
            }
        }
        int ans = 1;
        for (int i=m; i>=0; i--)
        {
            for (int j=n; j>=0; j--)
            {
                ans = max(ans, arr[i][j]);
            }
        }
        return ans - 1;
    }
};