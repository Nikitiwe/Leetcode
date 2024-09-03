class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans=1, l=0, r=0, c=0;
        while (r<s.size())
        {
            if (c<2)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==s.size()) break;
                if (s[r-1]==s[r]) c++;
            }
            else
            {
                if (s[l]==s[l+1]) c--;
                l++;
            }
        }
        return ans;
    }
};