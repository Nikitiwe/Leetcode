class Solution {
public:
    int numDecodings(string s) {
        int a=0, b=0, t=0;
        if (s[0]=='0') return 0;
        else a=1;
        if (s.size()==1) return 1;
        if ((s[0]-'0')*10+(s[1]-'0')<=26) b=1;
        if (s[1]!='0') b+=a;
        for (int i=2; i<s.size(); i++)
        {
            t=0;
            if (s[i]!='0') t+=b;
            if (s[i-1]!='0'&&(s[i-1]-'0')*10+(s[i]-'0')<=26) t+=a;
            if (t==0) return 0;
            a=b;
            b=t;
        }
        return b;
    }
};