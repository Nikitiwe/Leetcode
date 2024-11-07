class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (int i=0; i!=s.size(); i++) m[s[i]]++;
        int ans=0, isit=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second%2==1)
            {
                isit=1;
                break;
            }
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans+=i->second/2;
        }
        return ans*2+isit;
    }
};