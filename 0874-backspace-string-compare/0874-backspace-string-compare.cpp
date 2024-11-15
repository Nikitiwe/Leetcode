class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int l=s.size()-1, r=t.size()-1, sb=0, tb=0;
        while (l>=0||r>=0)
        {
            while (l>=0&&s[l]=='#')
            {
                sb++;
                l--;
                while (l>=0&&sb>0)
                {
                    if (s[l]=='#') sb++;
                    else sb--;
                    l--;
                }
            }
            while (r>=0&&t[r]=='#')
            {
                tb++;
                r--;
                while (r>=0&&tb>0)
                {
                    if (t[r]=='#') tb++;
                    else tb--;
                    r--;
                }
            }
            if (l>=0&&r>=0&&s[l]!=t[r]) return 0;
            else if (l>=0&&r>=0)
            {
                l--;
                r--;
            }
            else if ((l>=0&&r<0)||(r>=0&&l<0)) return 0;
        }
        return 1;
    }
};