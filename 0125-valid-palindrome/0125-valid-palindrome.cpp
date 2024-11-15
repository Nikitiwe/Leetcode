bool isd (char a)
{
    if (a>='a'&&a<='z') return 1;
    else return 0;
}

bool isu (char a)
{
    if (a>='A'&&a<='Z') return 1;
    else return 0;
}

bool isn (char a)
{
    if (a>='0'&&a<='9') return 1;
    else return 0;
}

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()<=1) return 1;
        int l=0, r=s.size()-1;
        while (l<=r)
        {
            while (isd(s[l])==0&&isu(s[l])==0&&isn(s[l])==0&&l<s.size()-1) l++;
            while (isd(s[r])==0&&isu(s[r])==0&&isn(s[r])==0&&r>0) r--;
            if (l>r) return 1;
            if (isu(s[l])) s[l]+='a'-'A';
            if (isu(s[r])) s[r]+='a'-'A';
            if (s[l]!=s[r]) return 0;
            r--;
            l++;
        }
        return 1;
    }
};