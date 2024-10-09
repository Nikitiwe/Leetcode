class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> u(26, 0), d=u;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='a') u[s[i]-'a']++;
            else d[s[i]-'A']++;
        }
        int ans=0;
        for (int i=0; i!=26; i++)
        {
            if (u[i]>0&&d[i]>0) ans++;
        }
        return ans;
    }
};