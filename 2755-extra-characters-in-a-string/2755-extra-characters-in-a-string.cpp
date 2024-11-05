class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        vector<int> ans(s.size()+1, 100);
        ans[0]=0;
        unordered_set<string> m(d.begin(), d.end());
        for (int i=0; i!=s.size(); i++)
        {
            string t;
            for (int j=i; j<s.size(); j++)
            {
                t+=s[j];
                if (m.count(t)>0) ans[j+1]=min(ans[j+1], ans[i]);
                ans[j+1]=min(ans[j+1], ans[j]+1);
            }
        }
        return ans[ans.size()-1];
    }
};