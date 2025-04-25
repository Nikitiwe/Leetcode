class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        vector<vector<int>> arr(s.size() + 1, vector<int>(3, 0));
        for (int i=0; i!=s.size(); i++)
        {
            arr[i+1][s[i]-'a']++;
            arr[i+1][0] += arr[i][0];
            arr[i+1][1] += arr[i][1];
            arr[i+1][2] += arr[i][2];
        }
        for (int j=0; j<3; j++) if (arr[s.size()][j] < k) return -1;
        int ans = s.size(), l = 0, r = s.size(), m;
        while (l <= r)
        {
            m = (l+r)/2;
            bool isit = 0;
            for (int i=0; i<=m; i++)
            {
                int a = arr[s.size()][0] - arr[s.size()-i][0] + arr[m-i][0];
                int b = arr[s.size()][1] - arr[s.size()-i][1] + arr[m-i][1];
                int c = arr[s.size()][2] - arr[s.size()-i][2] + arr[m-i][2];
                if (a >= k && b >= k && c >= k)
                {
                    isit = 1;
                    break;
                }
            }
            if (isit == 1)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};