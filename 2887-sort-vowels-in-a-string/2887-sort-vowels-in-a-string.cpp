class Solution {
public:
    string sortVowels(string s) {
        int ca=0, ce=0, ci=0, co=0, cu=0, cA=0, cE=0, cI=0, cO=0, cU=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='a') ca++;
            else if (s[i]=='e') ce++;
            else if (s[i]=='i') ci++;
            else if (s[i]=='o') co++;
            else if (s[i]=='u') cu++;
            else if (s[i]=='A') cA++;
            else if (s[i]=='E') cE++;
            else if (s[i]=='I') cI++;
            else if (s[i]=='O') cO++;
            else if (s[i]=='U') cU++;
        }
        string ta(ca,'a'), ti(ci,'i'), te(ce,'e'), to(co,'o'), tu(cu,'u'), tA(cA,'A'), tE(cE,'E'), 
        tI(cI,'I'), tO(cO,'O'), tU(cU,'U'), vow=tA+tE+tI+tO+tU+ta+te+ti+to+tu;
        int j=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            { s[i]=vow[j]; j++; }
        }
        return s;
    }
}; // Memory Limit Exceeded 2212/2216 testcases passed