class Solution {
public:
    char nextGreatestLetter(vector<char>& s, char t) {
        int id=s.size()-1;
        int l=0, r=s.size()-1, m;
        while (l<=r)
        {
            m=(l+r)/2;
            if (s[m]>t)
            {
                id=min(id, m);
                r=m-1;
            }
            else l=m+1;
        }
        if (s[id]>t) return s[id];
        return s[0];
    }
};