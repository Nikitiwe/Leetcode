class Solution {
public:
    string gcdOfStrings(string s, string w) {
        if (s.size()>w.size()) swap(s, w);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=w[i]) return "";
        }
        int d=gcd(s.size(), w.size());
        string t;
        for (int i=0; i!=d; i++) t+=s[i];
        for (int i=0; i!=w.size(); i++)
        {
            if (s[i%d]!=w[i]) return "";
        }
        return t;        
    }
};