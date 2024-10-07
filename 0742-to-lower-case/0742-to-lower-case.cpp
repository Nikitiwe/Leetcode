class Solution {
public:
    string toLowerCase(string s) {
        for (int i=0; i!=s.size(); i++)
        {
            // s[i]=tolower(s[i]);
            if (s[i]>='A'&&s[i]<='Z') s[i]+='a'-'A';
        }
        return s;
    }
};