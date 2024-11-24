class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<string, char> m;
        unordered_map<char, string> n;
        s+=' ';
        string t;
        int l=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') t+=s[i];
            else
            {
                if (m.count(t)==0&&n.count(p[l])==0)
                {
                    m[t]=p[l];
                    n[p[l]]=t;
                }
                else if (m.count(t)!=0&&n.count(p[l])!=0)
                {
                    if (m[t]!=p[l]||n[p[l]]!=t) return 0;
                }
                else return 0;
                t="";
                l++;
                if (l==p.size()&&i!=s.size()-1) return 0;
            }
        }
        if (l!=p.size()) return 0;
        else return 1;
    }
};