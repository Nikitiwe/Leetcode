class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        vector<string> ans;
        for (int i=0; i!=w.size(); i++)
        {
            unordered_map<char, char> m, rm;
            bool isit=1;
            for (int j=0; j!=w[i].size(); j++)
            {
                if (m.count(w[i][j])==0&&rm.count(p[j])==0)
                {
                    m[w[i][j]]=p[j];
                    rm[p[j]]=w[i][j];
                }
                else if (m[w[i][j]]!=p[j]||rm[p[j]]!=w[i][j])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans.push_back(w[i]);
        }
        return ans;
    }
};