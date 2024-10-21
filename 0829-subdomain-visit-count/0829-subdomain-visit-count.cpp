class Solution {
public:
    vector<string> subdomainVisits(vector<string>& s) {
        unordered_map<string, int> m;
        for (int i=0; i!=s.size(); i++)
        {
            int t=0, l=0;
            while (s[i][l]!=' ')
            {
                t*=10;
                t+=s[i][l]-'0';
                l++;
            }
            l++;
            string a, b;
            while (s[i][l]!='.')
            {
                a+=s[i][l];
                l++;
            }
            l++;
            while (l<s[i].size())
            {
                b+=s[i][l];
                l++;
                if (s[i][l]=='.') break;
            }
            if (l!=s[i].size())
            {
                l++;
                string c;
                while (l!=s[i].size())
                {
                    c+=s[i][l];
                    l++;
                }
                m[a+"."+b+"."+c]+=t;
                m[b+"."+c]+=t;
                m[c]+=t;
            }
            else
            {
                m[a+"."+b]+=t;
                m[b]+=t;
            }
        }
        vector<string> ans(m.size(), "");
        int j=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans[j]+=to_string(i->second);
            ans[j]+=" ";
            ans[j]+=i->first;
            j++;
        }
        return ans;
    }
};