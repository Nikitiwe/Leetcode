class Solution {
public:
    bool makeStringsEqual(string s, string w) {
        // i   0011
        // j   0101
        // xor 0110
        // or  0111
        int a = 0, b = 0;
        for (int i=0; i!=s.size(); i++)
        {
            a += s[i] - '0';
            b += w[i] - '0';
        }
        if ((a == 0 && b != 0) || (a != 0 && b == 0)) return 0;
        return 1;
    }
};