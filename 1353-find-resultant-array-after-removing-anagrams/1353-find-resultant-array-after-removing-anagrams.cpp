class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) {
        vector<string> ans;
        vector<int> t(26, 0), n=t, zero=n;
        for (int j=0; j!=w[w.size()-1].size(); j++) t[w[w.size()-1][j]-'a']++;
        for (int i=w.size()-1; i>0; i--)
        {
            if (w[i].size()!=w[i-1].size())
            {
                ans.push_back(w[i]);
                t=zero;
                for (int j=0; j!=w[i-1].size(); j++) t[w[i-1][j]-'a']++;
            }
            else
            {
                for (int j=0; j!=w[i-1].size(); j++) n[w[i-1][j]-'a']++;
                if (t!=n)
                {
                    ans.push_back(w[i]);
                    t=n;
                    n=zero;
                }
                else
                {
                    n=zero;
                }
            }
        }
        ans.push_back(w[0]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};