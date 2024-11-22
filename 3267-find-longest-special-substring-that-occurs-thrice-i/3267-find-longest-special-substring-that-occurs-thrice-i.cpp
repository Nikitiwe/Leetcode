class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> m;
        int ans=-1;
        for (int i=0; i!=s.size(); i++)
        {
            string t;
            t+=s[i];
            m[t]++;
            if (m[t]==3) ans=max(ans, 1);
            int l=i+1;
            while (l<s.size())
            {
                if (s[l]==t.back())
                {
                    t+=s[l];
                    m[t]++;
                    if (m[t]==3) ans=max(ans, (int)t.size());
                    l++;
                }
                else break;
            }
        }
        return ans;
    }
};