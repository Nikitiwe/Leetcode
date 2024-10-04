class Solution {
public:
    int countValidWords(string s) {
        int ans=0, ch=0, cp=0, isit=1;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==' '&&(i>0&&s[i-1]!=' ')&&isit==1)
            {
                ans++;
                ch=0; cp=0; isit=1;
            }
            else if (s[i]==' ')
            {
                ch=0; cp=0; isit=1;
            }
            else if (s[i]=='-')
            {
                ch++;
                if (ch>1) isit=0;
                if (i<1||(s[i-1]<'a'||s[i-1]>'z')) isit=0;
                if (i>=s.size()||(s[i+1]<'a'||s[i+1]>'z')) isit=0;
            }
            else if (s[i]=='!'||s[i]=='.'||s[i]==',')
            {
                cp++;
                if (cp>1) isit=0;
                if (i+1<s.size()&&s[i+1]!=' ') isit=0;
            }
            else if (s[i]>='0'&&s[i]<='9') isit=0;
        }
        if (isit==1&&s[s.size()-1]!=' ') ans++;
        return ans;
    }
};