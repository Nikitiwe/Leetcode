class Solution {
public:
    char nextGreatestLetter(vector<char>& s, char t) {
        char ans='z'+1;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]>t) ans=min(ans, s[i]);
        }
        if (ans=='z'+1) return s[0];
        return ans;
    }
};