class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        if (s.size()==1) return 1;
        int ans=1, l=0, r=1;
        unordered_set<char> m;
        m.insert(s[0]);
        while (r<s.size())
        {
            if (m.count(s[r])==0)
            {
                m.insert(s[r]);
                r++;
                ans=max(ans, r-l);
            }
            else
            {
                m.erase(s[l]);
                l++;
            }
            if (l==r)
            {
                m.insert(s[r]);
                r++;
            }
        }
        return ans;
    }   
};