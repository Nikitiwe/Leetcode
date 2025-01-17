class Solution {
public:
    string addStrings(string s, string w) {
        if (s.size()<w.size()) swap(s, w);
        string ans;
        int d=0;
        for (int i=0; i<s.size(); i++)
        {
            int t=s[s.size()-1-i]-'0';
            t+=d;
            if (w.size()-1>=i) t+=w[w.size()-1-i]-'0';
            d=t/10;
            ans+=to_string(t%10);
        }
        if (d>0) ans+=to_string(d);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};