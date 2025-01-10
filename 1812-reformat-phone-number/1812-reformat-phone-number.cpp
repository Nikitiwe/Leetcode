class Solution {
public:
    string reformatNumber(string s) {
        string ans, t;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='0'&s[i]<='9') t+=s[i];
        }
        int l=0;
        while (l+4<t.size())
        {
            ans+=t[l];
            l++;
            ans+=t[l];
            l++;
            ans+=t[l];
            l++;
            ans+='-';
        }
        if (l+4==t.size())
        {
            ans+=t[l];
            l++;
            ans+=t[l];
            l++;
            ans+='-';
            ans+=t[l];
            l++;
            ans+=t[l];
        }
        else if (l+3==t.size())
        {
            ans+=t[l];
            l++;
            ans+=t[l];
            l++;
            ans+=t[l];
        }
        else if (l+2==t.size())
        {
            ans+=t[l];
            l++;
            ans+=t[l];
        }
        return ans;
    }
};