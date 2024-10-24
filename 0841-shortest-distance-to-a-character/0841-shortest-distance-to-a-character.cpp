class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), s.size());
        for (int i=0; i!=s.size(); i++) if (s[i]==c) ans[i]=0;
        int t=ans[0];
        for (int i=0; i!=s.size(); i++)
        {
            if (ans[i]==0) t=0;
            else
            {
                t++;
                ans[i]=t;
            }
        }
        for (int i=s.size()-1; i>=0; i--)
        {
            if (ans[i]==0) t=0;
            else
            {
                t++;
                ans[i]=min(ans[i], t);
            }
        }
        return ans;
    }
};