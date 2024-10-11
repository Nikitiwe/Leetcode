class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]==s[i-1]||s[i]==s[i-1]+'A'-'a'||s[i]==s[i-1]-'A'+'a') continue;
            else ans++;
        }
        return ans;
    }
};