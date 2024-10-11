class Solution {
public:
    int minimumPushes(string s) {
        int ans=s.size();
        if (s.size()>8) ans+=s.size()-8;
        if (s.size()>16) ans+=s.size()-16;
        if (s.size()>24) ans+=s.size()-24;
        return ans;
    }
};