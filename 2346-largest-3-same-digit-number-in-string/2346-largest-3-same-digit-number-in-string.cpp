class Solution {
public:
    string largestGoodInteger(string s) {
        string ans;
        for (int i=2; i!=s.size(); i++)
        {
            if (s[i-2] == s[i-1] && s[i-1] == s[i])
            {
                if (ans.size() == 0)
                {
                    ans += s[i]; ans += s[i]; ans += s[i];
                }
                else
                {
                    string t;
                    t += s[i]; t += s[i]; t += s[i];
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};