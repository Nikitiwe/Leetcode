class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        int l=0, ans=1;
        for (int i=0; i!=s.size(); i++)
        {
            if (l+w[s[i]-'a']<=100) l+=w[s[i]-'a'];
            else
            {
                l=0;
                l+=w[s[i]-'a'];
                ans++;
            }
        }
        return {ans, l};
    }
};