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
                unordered_set<char> m;
                for (int k=l+1; k<r; k++)
                {
                    m.insert(s[k]);
                }
                ans+=m.size();
            }
        }
        return ans;
    }
};