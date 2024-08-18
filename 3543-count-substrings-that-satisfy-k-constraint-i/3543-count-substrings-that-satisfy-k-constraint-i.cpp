class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans=1, l=0, r=0, zero=0, one=0;
        if (s[r]=='1') one++;
        else zero++;
        while (r<s.size())
        {
            r++;
            if (r==s.size()) break;
            if (s[r]=='1') one++;
            else zero++;
            if (zero>k&&one>k)
            {
                if (s[r]=='1') one--;
                else zero--;
                r--;
                if (s[l]=='1') one--;
                else zero--;
                l++;
            }
            else
            {
                ans+=r-l+1;
            }
        }
        return ans;
    }
};