class Solution {
public:
    string convertDateToBinary(string s) {
        int a=0, l=0;
        string y, m, d;
        while (s[l]!='-')
        {
            a*=10;
            a+=s[l]-'0';
            l++;
        }
        l++;
        while (a>0)
        {
            if (a%2==0) y+='0';
            else y+='1';
            a/=2;
        }
        while (s[l]!='-')
        {
            a*=10;
            a+=s[l]-'0';
            l++;
        }
        l++;
        while (a>0)
        {
            if (a%2==0) m+='0';
            else m+='1';
            a/=2;
        }
        while (l<s.size())
        {
            a*=10;
            a+=s[l]-'0';
            l++;
        }
        while (a>0)
        {
            if (a%2==0) d+='0';
            else d+='1';
            a/=2;
        }
        reverse(y.begin(), y.end());
        reverse(m.begin(), m.end());
        reverse(d.begin(), d.end());
        return y+'-'+m+'-'+d;
    }
};