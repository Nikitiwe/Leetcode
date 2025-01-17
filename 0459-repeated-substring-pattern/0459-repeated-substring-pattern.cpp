class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int k=s.size();
        for (int i=1; i<=k/2; i++)
        {
            if (k%i==0)
            {
                string t=s.substr(0, i);
                bool isit=1;
                for (int j=i; j!=s.size(); j++)
                {
                    if (s[j]!=t[j%i])
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) return 1;
            }
        }
        return 0;
    }
};