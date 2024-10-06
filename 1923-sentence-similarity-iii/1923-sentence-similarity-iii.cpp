class Solution {
public:
    bool areSentencesSimilar(string s, string f) {
        if (s.size()<f.size()) swap(s, f);
        vector<string> a, b;
        string t;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') t+=s[i];
            else
            {
                a.push_back(t);
                t="";
            }
        }
        a.push_back(t);
        t="";
        for (int i=0; i!=f.size(); i++)
        {
            if (f[i]!=' ') t+=f[i];
            else
            {
                b.push_back(t);
                t="";
            }
        }
        b.push_back(t);
        while (0<b.size()&&a[a.size()-1]==b[b.size()-1])
        {
            a.pop_back();
            b.pop_back();
        }
        if (0==b.size()) return 1;
        int l=0;
        while (l<b.size()&&a[l]==b[l]) l++;
        if (l==b.size()) return 1;
        if (l==b.size()) return 1;
        // if (l+r-1==b.size()) return 1;
        return 0;
    }
};