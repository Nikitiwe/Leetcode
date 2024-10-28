class Solution {
public:
    string capitalizeTitle(string s) {
        string ans, t;
        s+=' ';
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') t+=s[i];
            else
            {
                if (t.size()<=2)
                {
                    if (t[0]>='A'&&t[0]<='Z') t[0]=t[0]+'a'-'A';
                    if (t.size()==2) if (t[1]>='A'&&t[1]<='Z') t[1]=t[1]+'a'-'A';
                }
                else
                {
                    if (t[0]>='a'&&t[0]<='z') t[0]=t[0]+'A'-'a';
                    for (int j=1; j<t.size(); j++)
                    {
                        if (t[j]>='A'&&t[j]<='Z') t[j]=t[j]+'a'-'A';
                    }
                }
                ans+=t;
                ans+=' ';
                t="";
            }
        }
        ans.pop_back();
        return ans;
    }
};