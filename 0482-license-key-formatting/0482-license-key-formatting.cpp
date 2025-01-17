class Solution {
public:
    string licenseKeyFormatting(string ss, int k) {
        string ans, s;
        for (int i=0; i!=ss.size(); i++)
        {
            if (ss[i]=='-') continue;
            else
            {
                if (ss[i]>='a'&&ss[i]<='z') s+=ss[i]-'a'+'A';
                else s+=ss[i];
            }
        }
        int a=s.size()%k;
        for (int i=0; i<a; i++)
        {
            ans+=s[i];
        }
        if (ans.size()>0&&ans.size()<s.size()) ans+='-';
        string t;
        for (int i=a; i<s.size(); i++)
        {
            if (t.size()!=k) t+=s[i];
            if (t.size()==k)
            {
                ans+=t;
                t="";
                if (i<s.size()-1) ans+='-';
            }
        }
        return ans;
    }
};