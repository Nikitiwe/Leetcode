class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r=s.size()-1;
        while(l<r)
        {
            while (l<s.size()&&s[l]!='a'&&s[l]!='e'&&s[l]!='i'&&s[l]!='o'&&s[l]!='u'&&
                    s[l]!='A'&&s[l]!='E'&&s[l]!='I'&&s[l]!='O'&&s[l]!='U') l++;
            while (r>=0&&s[r]!='a'&&s[r]!='e'&&s[r]!='i'&&s[r]!='o'&&s[r]!='u'&&
                    s[r]!='A'&&s[r]!='E'&&s[r]!='I'&&s[r]!='O'&&s[r]!='U') r--;
            if (l<r) swap (s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};