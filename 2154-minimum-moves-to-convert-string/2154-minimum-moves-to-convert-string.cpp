class Solution {
public:
    int minimumMoves(string s) {
        int ans=0, l=0;
        while (l<s.size())
        {
            if (s[l]=='X')
            {
                ans++;
                l+=3;
            }
            else l++;
        }
        return ans;
    }
};