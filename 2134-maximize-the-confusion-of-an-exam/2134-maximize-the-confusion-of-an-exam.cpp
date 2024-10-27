class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans=0, l=0, r=0, c=0;
        if (s[r]=='T') c++;
        while (r<s.size())
        {
            if (c<=k)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==s.size()) break;
                if (s[r]=='T') c++;
            }
            else
            {
                if (s[l]=='T') c--;
                l++;
            }
        }
        l=0; r=0; c=0;
        if (s[r]=='F') c++;
        while (r<s.size())
        {
            if (c<=k)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==s.size()) break;
                if (s[r]=='F') c++;
            }
            else
            {
                if (s[l]=='F') c--;
                l++;
            }
        }
        return ans;
    }
};