class Solution {
public:
    int maxRepeating(string s, string t) {
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            int l=i;
            while (l<s.size())
            {
                if (s[l]==t[(l-i)%t.size()]) l++;
                else break;
            }
            ans=max(ans, (l-i)/(int)t.size());
        }
        return ans;
    }
};