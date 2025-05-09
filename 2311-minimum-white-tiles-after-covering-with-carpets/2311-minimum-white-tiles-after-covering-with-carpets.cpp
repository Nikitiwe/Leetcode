class Solution {
public:
    int minimumWhiteTiles(string s, int n, int l) {
        if (s.size() <= n * l) return 0;
        vector<int> sum(s.size() + 1, 0);
        for (int i=0; i!=s.size(); i++)
        {
            sum[i+1] = sum[i] + s[i] - '0';
        }
        vector<vector<int>> arr(s.size(), vector<int>(n+1, s.size() + 1)); // ответ для конца k-ого ковра на i позиции
        for (int i=0; i<arr.size(); i++)
        {
            arr[i][0] = sum[i+1];
        }
        for (int k = 1; k<=n; k++)
        {
            for (int i=0; i<l; i++) arr[i][k] = 0;
            arr[l-1][k] = min(arr[l-1][k], arr[0][k-1]);
            for (int i=l; i<arr.size(); i++)
            {
                arr[i][k] = min(arr[i-1][k] + s[i] - '0', arr[i-l][k-1]);
            }
        }
        int res = arr[s.size() - 1][n];
        {
            int sum = 0;
            for (int i=arr.size() - 1; i>=0; i--)
            {
                res = min(res, arr[i][n] + sum);
                sum += s[i] - '0';
            }
        }
        return res;
    }
};