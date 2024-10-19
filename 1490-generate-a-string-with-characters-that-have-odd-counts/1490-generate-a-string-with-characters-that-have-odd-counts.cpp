class Solution {
public:
    string generateTheString(int n) {
        string s;
        for (int i=1; i<=n; i++) s+='a';
        if (n%2==0) s[0]='b';
        return s;
    }
};