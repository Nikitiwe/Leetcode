class Solution {
public:
    bool isNumber(string s) {
        int e=0, z=0, d=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (e==0)
            {
                if (s[i]!='e'&&s[i]!='E'&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))) return 0;
                else if (s[i]=='e'||s[i]=='E')
                {
                    e++;
                    if (i==s.size()-1) return 0;
                    if (i==0||(s[i-1]=='-'||s[i-1]=='+')) return 0;
                    if (e>1) return 0;
                    z=0;
                    d=0;
                }
                else if (s[i]=='+'||s[i]=='-')
                {
                    z++;
                    if (z>1) return 0;
                    if (i!=0&&(s[i-1]!='e'||s[i-1]!='E')) return 0;
                    if (i==s.size()-1||(s[i+1]!='.'&&(s[i+1]<'0'||s[i+1]>'9'))) return 0;
                }
                else if (s[i]=='.')
                {
                    d++;
                    if (d>1) return 0;
                    bool isit=0;
                    if (i>0&&s[i-1]>='0'&&s[i-1]<='9') isit=1;
                    if (i<s.size()-1&&s[i+1]>='0'&&s[i+1]<='9') isit=1;
                    if (isit==0) return 0;
                }
            }
            else
            {
                if (s[i]!='e'&&s[i]!='E'&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))) return 0;
                else if (s[i]=='e'||s[i]=='E')
                {
                    e++;
                    if (i==s.size()-1) return 0;
                    if (e>1) return 0;
                    z=0;
                    d=0;
                }
                else if (s[i]=='+'||s[i]=='-')
                {
                    z++;
                    if (z>1) return 0;
                    if (i!=0&&(s[i-1]!='e'&&s[i-1]!='E')) return 0;
                    if (i==s.size()-1||(s[i+1]!='.'&&(s[i+1]<'0'||s[i+1]>'9'))) return 0;
                }
                else if (s[i]=='.')
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};