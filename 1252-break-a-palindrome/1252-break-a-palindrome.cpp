class Solution {
public:
    string breakPalindrome(string pal) {
        if (pal.size()==1) return "";
        int f=1;
        for (int i=0; i!=pal.size()/2; i++)
        {
            if (pal[i]!='a') {pal[i]='a'; f=0; break;}
        }
        if (f==1) pal[pal.size()-1]='b';
        return pal;
    }
};