class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l=0, r=0, m=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='R') r++;
            else if (s[i]=='L') l++;
            else m++;
        }
        if (r>=l) return r+m-l;
        else return l+m-r;
    }
};