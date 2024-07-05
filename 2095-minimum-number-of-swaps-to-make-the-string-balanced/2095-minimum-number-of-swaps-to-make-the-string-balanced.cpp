class Solution {
public:
    int minSwaps(string s) {
        if (s=="[]") return 0;
        int l=0, r=0, count=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==']') {count++; if (count>l) l=count;}
            else count--;
        }
        count=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='[') {count++; if (count>r) r=count;}
            else count--;
        }
        return (max(l, r)+1)/2;
    }
};