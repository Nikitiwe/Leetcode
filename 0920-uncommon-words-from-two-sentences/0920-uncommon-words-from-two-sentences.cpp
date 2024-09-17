class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        int l=0;
        string t;
        while (l<s1.size())
        {
            if (s1[l]!=' ') t+=s1[l];
            else {m[t]++; t.clear();}
            l++;
        }
        l=0;
        m[t]++;
        t.clear();
        while (l<s2.size())
        {
            if (s2[l]!=' ') t+=s2[l];
            else {m[t]++; t.clear();}
            l++;
        }
        m[t]++;
        vector<string> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==1) ans.push_back(i->first);
        }
        return ans;
    }
};