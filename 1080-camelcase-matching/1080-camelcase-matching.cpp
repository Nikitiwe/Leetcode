class Solution {
public:
    vector<bool> camelMatch(vector<string>& s, string w) {
        vector<bool> ans(s.size(), 0);
        for (int i=0; i!=s.size(); i++)
        {
            int l=0, r=0;
            bool isit=1;
            while (l<s[i].size()&&r<w.size())
            {
                if (s[i][l]==w[r])
                {
                    l++;
                    r++;
                }
                else if (s[i][l]>='A'&&s[i][l]<='Z')
                {
                    isit=0;
                    break;
                }
                else l++;
            }
            if (isit==1) while (l<s[i].size())
            {
                if (s[i][l]>='A'&&s[i][l]<='Z')
                {
                    isit=0;
                    break;
                }
                l++;
            }
            if (isit==1&&r==w.size()) ans[i]=1;
        }
        return ans;
    }
};