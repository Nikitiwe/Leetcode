class Solution {
public:
    bool canBeEqual(string s, string w) {
        if (s == w) return 1;
        swap(s[0], s[2]);
        if (s == w) return 1;
        swap(s[1], s[3]);
        if (s == w) return 1;
        swap(s[0], s[2]);
        if (s == w) return 1;
        return 0;
    }
};