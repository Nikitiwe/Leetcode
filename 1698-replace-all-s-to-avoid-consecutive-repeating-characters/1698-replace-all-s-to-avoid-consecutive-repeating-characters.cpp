class Solution {
public:
    string modifyString(string s) {
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='?')
            {
                bool isa=1, isb=1, isc=1;
                if (i>0)
                {
                    if (s[i-1]=='a') isa=0;
                    else if (s[i-1]=='b') isb=0;
                    else if (s[i-1]=='c') isc=0;
                }
                if (i<s.size()-1)
                {
                    if (s[i+1]=='a') isa=0;
                    else if (s[i+1]=='b') isb=0;
                    else if (s[i+1]=='c') isc=0;
                }
                if (isa==1) s[i]='a';
                else if (isb==1) s[i]='b';
                else if (isc==1) s[i]='c';
            }
        }
        return s;
    }
};