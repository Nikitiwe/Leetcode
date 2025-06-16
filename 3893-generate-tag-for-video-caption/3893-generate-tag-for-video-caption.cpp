class Solution {
public:
    string generateTag(string s) {
        string ans = "#";
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (i > 0 && s[i-1] == ' ')
                {
                    ans += s[i] - 'a' + 'A';
                }
                else ans += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                if (i > 0 && s[i-1] == ' ')
                {
                    ans += s[i];
                }
                else ans += s[i] - 'A' + 'a';
            }
            if (ans.size() == 100) break;
        }
        if (ans.size() > 1 && ans[1] >= 'A' && ans[1] <= 'Z') ans[1] = ans[1] - 'A' + 'a';
        return ans;
    }
};