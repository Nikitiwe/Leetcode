class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        int l=0, c=1;
        string temp;
        while (l<s.size())
        {
            if (s[l]!=' ')
            {
                temp+=s[l];
                if (temp==t) return c;
            }
            else
            {
                temp="";
                c++;
            }
            l++;
        }
        return -1;
    }
};