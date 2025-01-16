class Solution {
public:
    string reverseStr(string s, int k) {
        int l=0, r=k, n=s.size();
        while (l<s.size())
        {
            r=min(r, n);
            for (int i=0; i!=min(k/2, (r-l)/2); i++)
            {
                swap(s[l+i], s[r-i-1]);
            }
            l+=2*k;
            r+=2*k;
        }
        return s;
    }
};