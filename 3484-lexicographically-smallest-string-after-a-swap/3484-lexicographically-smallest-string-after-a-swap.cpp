class Solution {
public:
    string getSmallestString(string s) {
        int i=0;
        while (i!=s.size()-1)
        {
            if (s[i]%2==s[i+1]%2&&s[i]>s[i+1]) {swap(s[i+1], s[i]); break;}
            i++;
        }
        return s;
    }
};