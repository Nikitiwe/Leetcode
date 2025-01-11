class Solution {
public:
    string reorderSpaces(string s) {
        int n=0, x=0;
        int a=0, b=s.size()-1;
        while (s[a]==' ') a++;
        while (s[b]==' ') b--;
        for (int i=a; i<b; i++)
        {
            if (i>0&&s[i]==' '&&s[i-1]!=' ') x++;
        }
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==' ')
            {
                n++;
            }
        }
        string ans;
        int l=0;
        while (l<s.size()&&s[l]==' ') l++;
        if (x>0) while (l<s.size())
        {
            if (s[l]!=' ')
            {
                ans+=s[l];
                if (ans.size()==s.size()) break;
                l++;
            }
            else
            {
                for (int i=0; i!=n/x; i++)
                {
                    ans+=' ';
                    if (ans.size()==s.size()) break;
                }
                while (l<s.size()&&s[l]==' ') l++;
            }
        }
        else while (l<s.size())
        {
            if (s[l]!=' ')
            {
                ans+=s[l];
            }
            l++;
        }
        while (ans.size()<s.size()) ans+=' ';
        return ans;
    }
};