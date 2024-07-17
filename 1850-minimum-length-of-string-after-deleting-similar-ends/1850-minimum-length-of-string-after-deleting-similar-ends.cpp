class Solution {
public:
    int minimumLength(string s) {
        if (s.size()==1) return 1;
        int l=0, r=s.size()-1;
        while (l<r)
        {
            if (s[l]!=s[r]) break;
            while (l<r&&s[l+1]==s[l]) l++;
            while (r>=l&&s[r-1]==s[r]) r--;
            if (l<s.size()-1) l++;
            if (r>=1) r--;
        }
        return max(0, r-l+1);
    }
};