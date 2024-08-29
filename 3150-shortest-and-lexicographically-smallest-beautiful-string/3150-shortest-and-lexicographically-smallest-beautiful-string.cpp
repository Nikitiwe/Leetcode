class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0, r=0, count=0;
        string ans, t;
        t+=s[0];
        if (s[0]=='1') count++;
        if (k==1&&count==1) return t;
        while (r<s.size())
        {
            if (count<k)
            {
                r++;
                if (r==s.size()) break;
                t+=s[r];
                if (s[r]=='1') count++;
                if (count==k)
                {
                    if (t.size()<ans.size()) ans=t;
                    else if (t.size()==ans.size())
                    {
                        int ll=0;
                        while (ll<ans.size()&&ans[ll]==t[ll]) ll++;
                        if (ll<ans.size())
                        {
                            if (ans[ll]>t[ll]) ans=t;
                        }
                    }
                    else if (ans.size()==0) ans=t;
                }
            }
            else
            {
                if (count==k)
                {
                    if (t.size()<ans.size()) ans=t;
                    else if (t.size()==ans.size())
                    {
                        int ll=0;
                        while (ll<ans.size()&&ans[ll]==t[ll]) ll++;
                        if (ll<ans.size())
                        {
                            if (ans[ll]>t[ll]) ans=t;
                        }
                    }
                    else if (ans.size()==0) ans=t;
                }
                t.erase(0, 1);
                if (s[l]=='1') count--;
                l++;
            }
        }
        return ans;
    }
};