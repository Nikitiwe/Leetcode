class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        for (int i=0; i!=s.size(); i++) m[s[i]]++;
        int t;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            t=i->second;
            break;
        }
        for (auto i=m.begin(); i!=m.end(); i++) if (i->second!=t) return 0;
        return 1;
    }
};