class Solution {
public:
    int minimumDeleteSum(string s, string w) {
        vector<vector<int>> arr(s.size()+1, vector<int>(w.size()+1, 10000000));
        arr[0][0] = 0;
        for (int i=0; i<s.size(); i++)
        {
            arr[i+1][0] = s[i];
            arr[i+1][0] += arr[i][0];
        }
        for (int j=0; j<w.size(); j++)
        {
            arr[0][j+1] = w[j];
            arr[0][j+1] += arr[0][j];
        }
        for (int i=1; i<=s.size(); i++)
        {
            for (int j=1; j<=w.size(); j++)
            {
                if (s[i-1] == w[j-1])
                {
                    arr[i][j] = min(arr[i][j], arr[i-1][j-1]);
                }
                else
                {
                    int r = arr[i-1][j-1];
                    arr[i][j] = min(arr[i][j], arr[i-1][j-1] + s[i-1] + w[j-1]);
                }
                if (i>1)
                {
                    arr[i][j] = min(arr[i][j], arr[i-1][j] + s[i-1]);
                }
                if (j>1)
                {
                    arr[i][j] = min(arr[i][j], arr[i][j-1] + w[j-1]);
                }
            }
        }
        return arr[s.size()][w.size()];
    }
};