class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> m;
        for (int i=0; i!=s.size(); i++) m.insert(s[i]);
        return m.size();
    }
};