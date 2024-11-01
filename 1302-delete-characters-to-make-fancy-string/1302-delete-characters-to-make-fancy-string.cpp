class Solution {
public:
    string makeFancyString(string s) {
        if (s.size()<3) return s;
        string ans;
        ans+=s[0];
        ans+=s[1];
        for (int i=2; i<s.size(); i++)
        {
            if (ans[ans.size()-1]!=s[i])
            {
                ans+=s[i];
            }
            else if (ans[ans.size()-2]!=s[i])
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};