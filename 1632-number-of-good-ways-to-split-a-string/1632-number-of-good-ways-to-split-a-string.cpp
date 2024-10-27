class Solution {
public:
    int numSplits(string s) {
        vector<int> l(s.size()+1, 0), r=l;
        unordered_set<char> m, n;
        for (int i=0; i!=s.size(); i++)
        {
            m.insert(s[i]);
            l[i+1]=m.size();
        }
        m=n;
        for (int i=s.size()-1; i>=0; i--)
        {
            m.insert(s[i]);
            r[i]=m.size();
        }
        int ans=0;
        for (int i=0; i!=l.size(); i++)
        {
            if (l[i]==r[i]) ans++;
        }
        return ans;
    }
};