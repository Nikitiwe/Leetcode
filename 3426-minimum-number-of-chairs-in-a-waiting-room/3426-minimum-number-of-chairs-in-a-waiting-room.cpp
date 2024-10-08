class Solution {
public:
    int minimumChairs(string s) {
        int ans=0, t=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='E')
            {
                ans++;
                t=max(t, ans);
            }
            else ans--;
        }
        return t;
    }
};