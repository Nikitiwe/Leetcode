class Solution {
public:
    int minLength(string s) {
        int l=0;
        string t;
        t+=s[l];
        l++;
        while (1)
        {
            if (t.size()>1&&((t[t.size()-2]=='A'&&t[t.size()-1]=='B')||(t[t.size()-2]=='C'&&t[t.size()-1]=='D')))
            {
                t.erase(t.size()-2);
            }
            else
            {
                if (l<s.size()) t+=s[l];
                l++;
            }
            if (l>s.size()) break;
        }
        return t.size();
    }
};