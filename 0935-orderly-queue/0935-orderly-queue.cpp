class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans=s;
        if (k==1)
        {
            for (int i=0; i!=s.size(); i++)
            {
                string t=s;
                for (int j=0; j!=s.size(); j++)
                {
                    t[j]=s[(j+i)%s.size()];
                }
                ans=min(ans, t);
            }
        }
        else
        {
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};