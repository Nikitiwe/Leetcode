class Solution {
public:
    int minDistance(string s, string w) {
        vector<vector<int>> arr(w.size()+1, vector<int>(s.size()+1, 1000));
        for (int i=0; i<=w.size(); i++) arr[i][0] = i;
        for (int j=0; j<=s.size(); j++) arr[0][j] = j;
        for (int i=1; i<=w.size(); i++)
        {
            for (int j=1; j<=s.size(); j++)
            {
                arr[i][j] = min({arr[i-1][j-1] + 1, arr[i-1][j] + 1, arr[i][j-1] + 1});
                if (w[i-1] == s[j-1]) arr[i][j] = min(arr[i][j], arr[i-1][j-1]);
            }
        }
        return arr[w.size()][s.size()];
    }
};