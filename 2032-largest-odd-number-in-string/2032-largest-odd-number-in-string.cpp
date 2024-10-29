class Solution {
public:
    string largestOddNumber(string s) {
        while (s.size()>0&&(s[s.size()-1]-'0')%2==0) s.pop_back();
        return s;
    }
};