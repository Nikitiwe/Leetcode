class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        for (int i=0; i!=26; i++)
        {
            if (s.find('a'+i)!=string::npos)
            {
                int l=s.find('a'+i), r=s.find_last_of('a'+i);
                if (r-l<2) continue;
                string t=s.substr(l+1, r-1-l);
                for (int k=0; k!=26; k++)
                {
                    if (t.find('a'+k)!=string::npos&&t.find('a'+k)<r-l-1) ans++;
                }
            }
        }
        return ans;
    }
};