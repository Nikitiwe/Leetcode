class Solution {
public:
    void f(vector<string> &ans, string &s, unordered_set<string> &m, string t, int l)
    {
        if (l == s.size())
        {
            ans.push_back(t);
            return;
        }
        string temp;
        for (int i=l; i<s.size(); i++)
        {
            temp += s[i];
            if (m.count(temp) != 0)
            {
                string tt = t;
                if (t.size() > 0) tt += ' ';
                tt += temp;
                f(ans, s, m, tt, i+1);
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string t;
        unordered_set<string> m;
        for (int i=0; i!=wordDict.size(); i++) m.insert(wordDict[i]);
        f(ans, s, m, t, 0);
        return ans;
    }
};