class Solution {
public:
    bool isLongPressedName(string s, string f) {
        int l=0, r=0, cs=0, cf=0;
        while (l<s.size())
        {
            cs=0; cf=0;
            int a=l;
            while (l<s.size()&&s[l]==s[a])
            {
                l++;
                cs++;
            }
            while (r<f.size()&&f[r]==s[a])
            {
                r++;
                cf++;
            }
            if (cf<cs) return 0;
        }
        if (r<f.size()) return 0;
        return 1;
    }
};