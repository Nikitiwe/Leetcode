class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0, r=0;
        while (l<s.size()&&r<t.size())
        {
            if (s[l]==t[r]) l++;
            r++;
        }
        if (l==s.size()) return 1;
        else return 0;
    }
};