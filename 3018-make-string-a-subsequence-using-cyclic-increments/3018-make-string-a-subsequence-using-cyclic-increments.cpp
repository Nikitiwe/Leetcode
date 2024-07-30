class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int l=0;
        for (int i=0; i!=s1.size(); i++)
        {
            if (s1[i]==s2[l]||s1[i]+1==s2[l]||(s1[i]=='z'&&s2[l]=='a'))
            {
                l++;
                if (l==s2.size()) return 1;
            }
        }
        return 0;
    }
};