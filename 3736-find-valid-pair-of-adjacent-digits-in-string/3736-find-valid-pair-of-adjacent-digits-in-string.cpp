class Solution {
public:
    string findValidPair(string s) {
        vector<int> c(10, 0);
        for (int i=0; i!=s.size(); i++) c[s[i]-'0']++;
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i] != s[i+1] && s[i]-'0' == c[s[i]-'0'] && s[i+1]-'0' == c[s[i+1]-'0'])
            return to_string(s[i]-'0') + to_string(s[i+1]-'0');
        }
        return "";
    }
};