class Solution {
public:
    string finalString(string s) {
        string r, l;
        int c=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='i')
            {
                c++;
            }
            else if (c%2==0) r+=s[i];
            else l+=s[i];
        }
        reverse(l.begin(), l.end());
        l+=r;
        if (c%2==0) return l;
        else
        {
            reverse(l.begin(), l.end());
            return l;
        }
    }
};