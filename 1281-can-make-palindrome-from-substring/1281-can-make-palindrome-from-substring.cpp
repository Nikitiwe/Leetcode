class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool> ans(q.size(), 0);
        vector<vector<int>> arr(s.size()+1, vector<int>(26, 0));
        vector<int> t(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            t[s[i]-'a']++;
            arr[i+1] = t;
        }
        for (int i=0; i!=q.size(); i++)
        {
            vector<int> t(26, 0);
            for (int j=0; j!=26; j++) t[j] = arr[q[i][1]+1][j] - arr[q[i][0]][j];
            int odd = 0;
            for (int j=0; j!=26; j++)
            {
                if (t[j] % 2 == 1 ) odd++;
            }
            odd -= 2*q[i][2];
            if (odd <= 0 || (odd == 1 && (q[i][1] - q[i][0] + 1) %2 == 1) ) ans[i] = 1;
        }
        return ans;
    }
};