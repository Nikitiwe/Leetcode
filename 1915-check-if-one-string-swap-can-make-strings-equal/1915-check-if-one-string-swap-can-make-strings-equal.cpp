class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1==s2) return 1;
        int l=0, r=s1.size()-1;
        while (l<s1.size()&&s1[l]==s2[l]) l++;
        while (r>=0&&s1[r]==s2[r]) r--;
        if (l<s1.size()&&r>=0) swap (s1[l], s1[r]);
        if (s1==s2) return 1;
        else return 0;
        
    }
};