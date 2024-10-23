class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==t[l]) l++;
            if (l==t.size()) return 0;
        }
        return t.size()-l;
    }
};