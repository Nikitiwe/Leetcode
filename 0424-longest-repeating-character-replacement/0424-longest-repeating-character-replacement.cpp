class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for (int kk=0; kk!=26; kk++)
        {
            int l=0, r=0, c=0;
            if (s[0]!='A'+kk) c++;
            while (r<s.size())
            {
                if (c<=k)
                {
                    ans=max(ans, r-l+1);
                    r++;
                    if (r==s.size()) break;
                    if (s[r]!='A'+kk) c++;
                }
                else
                {
                    if (s[l]!='A'+kk) c--;
                    l++;
                }
            }
        }
        return ans;
    }
};