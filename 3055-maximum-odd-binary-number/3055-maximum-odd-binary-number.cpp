class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int sum=0;
        for (int i=0; i!=s.size(); i++) sum+=s[i]-'0';
        for (int i=0; i<=sum-2; i++) s[i]='1';
        for (int i=sum-1; i<=(int)s.size()-2; i++) s[i]='0';
        s[s.size()-1]='1';
        return s;
    }
};