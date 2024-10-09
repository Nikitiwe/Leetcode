class Solution {
public:
    bool isValid(string s) {
        if (s.size()<3) return 0;
        int v=0, c=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
                s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') v++;
            else if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) c++;
            else if (s[i]>='0'&&s[i]<='9') continue;
            else return 0;
        }
        if (c>=1&&v>=1) return 1;
        else return 0;
    }
};