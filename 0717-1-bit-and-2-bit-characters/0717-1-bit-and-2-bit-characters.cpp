class Solution {
public:
    bool isOneBitCharacter(vector<int>& s) {
        if (s.size()==1) return 1-s[0];
        int l=0;
        while (l<s.size())
        {
            if (s[l]==0) l++;
            else l+=2;
            if (l==s.size()-1&&s.back()==0) return 1;
        }
        return 0;
    }
};