class Solution {
public:
    bool halvesAreAlike(string s) {
        int c=0;
        for (int i=0; i!=s.size()/2; i++)
        {
            if (s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u'||
                s[i]=='A'||s[i]=='O'||s[i]=='E'||s[i]=='I'||s[i]=='U') c++;
        }
        for (int i=s.size()/2; i!=s.size(); i++)
        {
            if (s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u'||
                s[i]=='A'||s[i]=='O'||s[i]=='E'||s[i]=='I'||s[i]=='U') c--;
        }
        if (c==0) return 1;
        else return 0;
    }
};