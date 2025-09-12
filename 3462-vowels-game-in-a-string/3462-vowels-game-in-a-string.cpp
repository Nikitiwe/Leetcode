class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='e'||s[i]=='u') return 1;
        }
        return 0;
    }
};