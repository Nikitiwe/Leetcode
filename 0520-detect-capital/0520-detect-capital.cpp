class Solution {
public:
    bool detectCapitalUse(string s) {
        int count=0;
        bool isf=0;
        if (s[0]<='Z') isf=1;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]<='Z') count++;
        }
        if (count==0||(isf==1&&count==1)||count==s.size()) return 1;
        else return 0;
    }
};