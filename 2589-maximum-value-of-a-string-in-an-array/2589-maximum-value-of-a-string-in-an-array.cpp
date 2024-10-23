class Solution {
public:
    int maximumValue(vector<string>& s) {
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            int t=0;
            for (int j=0; j!=s[i].size(); j++)
            {
                if (s[i][j]>='0'&&s[i][j]<='9')
                {
                    t*=10;
                    t+=s[i][j]-'0';
                }
                else
                {
                    t=0;
                    ans=max(ans, (int)s[i].size());
                    break;
                }
            }
            ans=max(ans, t);
        }
        return ans;
    }
};