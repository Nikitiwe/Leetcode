class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int c = 1;
        for (int i=1; i<=k; i++) c *= 2;
        if (s.size() + 1 < c + k) return 0;
        unordered_set<string> m;
        for(int i=0; i<s.size() - k + 1; i++)
        {
            string t;
            for (int j=0; j<k; j++) if (i+j < s.size()) t += s[i+j];
            if (t.size() == k) m.insert(t);
        }
        if (m.size() == c) return 1;
        else return 0;
    }
};