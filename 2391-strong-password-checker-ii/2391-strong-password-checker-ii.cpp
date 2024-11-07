class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if (s.size()<8) return 0;
        bool isl=0, isu=0, isd=0, iss=0;
        for (int i=1; i!=s.size(); i++) if (s[i]==s[i-1]) return 0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='0'&&s[i]<='9') isd=1;
            else if (s[i]>='a'&&s[i]<='z') isl=1;
            else if (s[i]>='A'&&s[i]<='Z') isu=1;
            else iss=1;
        }
        if (isl==1&&isu==1&&isd==1&&iss==1) return 1;
        else return 0;
    }
};