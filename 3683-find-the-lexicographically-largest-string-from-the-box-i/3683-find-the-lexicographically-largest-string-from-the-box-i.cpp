class Solution {
public:
    string answerString(string s, int n) {
        if (n == 1) return s;
        string ans;
        ans += s[0];
        int m = s.size() + 1 - n;
        for (int i=0; i<s.size(); i++)
        {
            string t;
            for (int j=i; j<s.size(); j++)
            {
                t += s[j];
                if (t.size() == m)
                {
                    ans = max(ans, t);
                    break;
                }
            }
            ans = max(ans, t);
        }
        return ans;
    }
};