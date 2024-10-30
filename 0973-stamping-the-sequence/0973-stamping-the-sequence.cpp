class Solution {
public:
    vector<int> movesToStamp(string s, string t) {
        if (t.size()<s.size()) return {};
        vector<int> ans;
        int c=0;
        while (c<t.size())
        {
            int cc=c;
            for (int i=0; i<t.size()-s.size()+1; i++)
            {
                int l=0, x=-1, lc=0;
                for (int j=0; j<s.size(); j++)
                {
                    if (t[i+j]==s[l])
                    {
                        l++;
                    }
                    else if (t[i+j]=='?')
                    {
                        l++;
                        lc++;
                    }
                    else
                    {
                        l=0;
                        lc=0;
                        break;
                    }
                }
                if (l==s.size()&&lc<s.size())
                {
                    x=i;
                }
                if (x>-1)
                {
                    ans.push_back(x);
                    for (int j=0; j!=s.size(); j++)
                    {
                        if (t[x+j]!='?')
                        {
                            c++;
                            t[x+j]='?';
                        }
                    }
                    break;
                }
            }
            if (c!=cc) continue;
            for (int i=t.size()-s.size(); i>=0; i--)
            {
                int l=0, x=-1, lc=0;
                for (int j=0; j<s.size(); j++)
                {
                    if (t[i+j]==s[l])
                    {
                        l++;
                    }
                    else if (t[i+j]=='?')
                    {
                        l++;
                        lc++;
                    }
                    else
                    {
                        l=0;
                        lc=0;
                        break;
                    }
                }
                if (l==s.size()&&lc<s.size())
                {
                    x=i;
                }
                if (x>-1)
                {
                    ans.push_back(x);
                    for (int j=0; j!=s.size(); j++)
                    {
                        if (t[x+j]!='?')
                        {
                            c++;
                            t[x+j]='?';
                        }
                    }
                    break;
                }
            }
            if (cc==c) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};