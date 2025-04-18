class Solution {
public:
    string shortestCommonSupersequence(string s, string w) {
        vector<vector<int>> arr(s.size() + 1, vector<int>(w.size() + 1, 3000));
        vector<vector<string>> ans(s.size() + 1, vector<string>(w.size() + 1, ""));
        vector<vector<string>> p(s.size() + 1, vector<string>(w.size() + 1, ""));
        arr[0][0] = 0;
        for (int i=0; i!=s.size(); i++)
        {
            arr[i+1][0] = i+1;
            ans[i+1][0] = s[i];
            p[i+1][0] = "i";
        }
        for (int j=0; j!=w.size(); j++)
        {
            arr[0][j+1] = j+1;
            ans[0][j+1] = w[j];
            p[0][j+1] = "j";
        }
        for (int i=1; i<=s.size(); i++)
        {
            for (int j=1; j<=w.size(); j++)
            {
                if (s[i-1] == w[j-1])
                {
                    arr[i][j] = arr[i-1][j-1] + 1;
                    ans[i][j] = s[i-1];
                }
                else
                {
                    if (arr[i][j-1] <= arr[i-1][j])
                    {
                        arr[i][j] = arr[i][j-1] + 1;
                        ans[i][j] = w[j-1];
                        p[i][j] = "j";
                    }
                    else
                    {
                        arr[i][j] = arr[i-1][j] + 1;
                        ans[i][j] = s[i-1];
                        p[i][j] = "i";
                    }
                }
            }
        }
        string res;
        int a = s.size(), b = w.size();
        while (a >= 0 && b >= 0)
        {
            res += ans[a][b];
            if (p[a][b] == "i") a--;
            else if (p[a][b] == "j") b--;
            else {a--; b--;}

        }
        reverse(res.begin(), res.end());
        return res;
    }
};