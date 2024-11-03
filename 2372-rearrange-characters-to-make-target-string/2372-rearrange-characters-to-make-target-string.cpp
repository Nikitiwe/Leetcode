class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> tar(26, 0), arr=tar;
        for (int i=0; i!=t.size(); i++) tar[t[i]-'a']++;
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        int ans=1000;
        for (int i=0; i!=26; i++)
        {
            if (tar[i]!=0)
            {
                ans=min(ans, arr[i]/tar[i]);
            }
        }
        return ans;
    }
};