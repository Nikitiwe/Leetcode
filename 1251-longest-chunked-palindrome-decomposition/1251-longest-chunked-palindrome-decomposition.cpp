class Solution {
public:
    int longestDecomposition(string s) {
        if (s.size()==1) return 1;
        int ans=0, isit;
        string l, r;
        for (int i=0; i<s.size()/2; i++)
        {
            l+=s[i];
            r+=s[s.size()-1-i];
            isit=1;
            for (int j=0; j!=l.size(); j++)
            {
                if(l[j]!=r[l.size()-1-j]) {isit=0; break;}
            }
            if (isit==1)
            {
                ans+=2;
                l.clear();
                r.clear();
            }
        }
        if (s.size()%2==1||l.size()>0) ans++;
        return ans;
    }
};