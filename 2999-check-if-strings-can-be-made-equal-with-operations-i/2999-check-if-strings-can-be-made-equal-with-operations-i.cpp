class Solution {
public:
    bool canBeEqual(string s, string w) {
        if (s == w) return 1;
        if (string(1, s[2]) + s[1] + s[0] + s[3] == w) return 1;
        if (string(1, s[2]) + s[3] + s[0] + s[1] == w) return 1;
        if (string(1, s[0]) + s[3] + s[2] + s[1] == w) return 1;
        return 0;
    }
};