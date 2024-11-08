class Solution {
public:
    long long minimumCost(string s) {
        if (s.size()==1) return 0;
        vector<long long> l(s.size(), 0), r=l;
        for (int i=1; i!=l.size(); i++)
        {
            l[i]+=l[i-1];
            if (s[i]!=s[i-1]) l[i]+=i;
        }
        for (int i=r.size()-2; i>=0; i--)
        {
            r[i]+=r[i+1];
            if (s[i]!=s[i+1]) r[i]+=r.size()-i-1;
        }
        long long ans=1000000000000000;
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i]==s[i+1]) ans=min(ans, l[i]+r[i+1]);
            else ans=min(ans, l[i]+r[i+1]+min(i+1, (int)s.size()-i-1));
        }
        return ans;
    }
};