class Solution {
public:
    int removePalindromeSub(string s) {
        bool isit=1;
        for (int i=0; i!=s.size()/2; i++)
        {
            if (s[i]!=s[s.size()-1-i])
            {
                isit=0;
                break;
            }
        }
        if (isit==1) return 1;
        else return 2;
    }
};