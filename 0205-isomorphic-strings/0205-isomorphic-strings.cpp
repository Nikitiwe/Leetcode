class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, n;
        for (int i=0; i!=s.size(); i++)
        {
            if (m.count(s[i])==0) m[s[i]]=t[i];
            else if (m[s[i]]!=t[i]) return 0;
            if (n.count(t[i])==0) n[t[i]]=s[i];
            else if (n[t[i]]!=s[i]) return 0;
            s[i]=m[s[i]];
        }
        return s==t;
    }
};