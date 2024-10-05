class Solution {
public:
    int countConsistentStrings(string s, vector<string>& w) {
        unordered_set<char> m;
        for (int i=0; i!=s.size(); i++) m.insert(s[i]);
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            bool isit=1;
            for (int j=0; j!=w[i].size(); j++)
            {
                if (m.count(w[i][j])==0)
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans++;
        }
        return ans;
    }
};