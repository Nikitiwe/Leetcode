class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while (l<r)
        {
            if (s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                int a=l, b=r;
                a++;
                bool isit=1;
                while (a<b)
                {
                    if (s[a]==s[b])
                    {
                        a++;
                        b--;
                    }
                    else
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) return 1;
                a=l; b=r;
                b--;
                isit=1;
                while (a<b)
                {
                    if (s[a]==s[b])
                    {
                        a++;
                        b--;
                    }
                    else
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) return 1;
                else return 0;
            }
        }
        return 1;
    }
};