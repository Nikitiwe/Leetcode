class Solution {
public:
    string decodeString(string s) {
        string ans;
        int r, temp, p, count;
        while (find(s.begin(), s.end(), '[')!=s.end())
        {
        r=0;
        while (r<s.size())
        {
            if (s[r]>='a'&&s[r]<='z') {ans+=s[r]; r++;}
            else
            {
                temp=0;
                while (s[r]>='0'&&s[r]<='9')
                {
                    temp=10*temp+s[r]-'0';
                    r++;
                }
                for (int i=0; i!=temp; i++)
                {
                    p=r;
                    count=1;
                    p++;
                    while (count>0)
                    {
                        if (p<s.size()&&s[p]=='[') {count++; ans+=s[p]; p++;}
                        else if (p<s.size()&&s[p]==']') {count--; if (count!=0) {ans+=s[p]; p++;}}
                        else if (p<s.size()) {ans+=s[p]; p++;}
                    }
                }
                r=p;
                r++;
            }
        }
        s=ans;
        ans.clear();
        }
        return s;
    }
};