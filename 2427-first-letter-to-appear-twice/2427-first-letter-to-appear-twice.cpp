class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> m;
        for (int i=0; i!=s.size(); i++)
        {
            if (m.count(s[i])==1) return s[i];
            m.insert(s[i]);
        }
        return '!';
    }
};