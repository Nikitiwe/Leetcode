class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=0; j<s.size(); j++)
            {
                if (i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j])
                {
                    ans++;
                    continue;
                }
                else break;
            }
            for (int j=1; j<s.size(); j++)
            {
                if (i-j+1>=0&&i+j<s.size()&&s[i-j+1]==s[i+j])
                {
                    ans++;
                    continue;
                }
                else break;
            }
        }
        return ans;
    }
};