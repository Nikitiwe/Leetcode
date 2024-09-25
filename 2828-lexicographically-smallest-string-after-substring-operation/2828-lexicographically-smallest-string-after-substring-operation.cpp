class Solution {
public:
    string smallestString(string s) {
        int l=0;
        while (l<s.size()&&s[l]=='a') l++;
        if (l==s.size()) s[s.size()-1]='z';
        else while (l<s.size())
        {
            if (s[l]=='a') break;
            else
            {
                int t=s[l]-'a'-1;
                s[l]='a'+t;
            }
            l++;
        }
        return s;
    }
};