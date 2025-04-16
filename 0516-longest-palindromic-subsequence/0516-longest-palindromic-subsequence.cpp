class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string w = s;
        reverse(w.begin(), w.end());
        vector<vector<int>> arr(s.size(), vector<int>(s.size(), 0));
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=0; j!=s.size(); j++)
            {
                if (i>0 && j>0) arr[i][j] = arr[i-1][j-1];
                if (s[i] == w[j]) arr[i][j]++;
                if (i>0) arr[i][j] = max(arr[i][j], arr[i-1][j]);
                if (j>0) arr[i][j] = max(arr[i][j], arr[i][j-1]);
            }
        }
        return arr[s.size()-1][s.size()-1];
    }
};