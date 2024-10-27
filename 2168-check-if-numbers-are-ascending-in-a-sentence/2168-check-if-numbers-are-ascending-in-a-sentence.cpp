class Solution {
public:
    bool areNumbersAscending(string s) {
        int t=0, pr=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>'9'||s[i]<'0') continue;
            else
            {
                t*=10;
                t+=s[i]-'0';
                if (i+1==s.size()||s[i+1]==' ')
                {
                    if (t<=pr) return 0;
                    pr=t;
                    t=0;
                }
            }
        }
        return 1;
    }
};