class Solution {
public:
    string removeStars(string s) {
        stack<char> m;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == '*') m.pop();
            else m.push(s[i]);
        }
        string ans;
        while (m.size() > 0)
        {
            ans += m.top();
            m.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};