class Solution {
public:
    string toGoatLatin(string s) {
        s+=' ';
        string ans, t, d;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') t+=s[i];
            else
            {
                if (ans.size()!=0) ans+=' ';
                d+='a';
                if (t[0]=='a'||t[0]=='e'||t[0]=='i'||t[0]=='o'||t[0]=='u'||
                    t[0]=='A'||t[0]=='E'||t[0]=='I'||t[0]=='O'||t[0]=='U')
                {
                    ans+=t;
                    ans+="ma";
                }
                else
                {
                    char tt=t[0];
                    reverse(t.begin(), t.end());
                    t.pop_back();
                    reverse(t.begin(), t.end());
                    t+=tt;
                    ans+=t;
                    ans+="ma";
                }
                ans+=d;
                t="";
            }
        }
        return ans;
    }
};