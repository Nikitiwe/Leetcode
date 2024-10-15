class Solution {
public:
    bool isAcronym(vector<string>& w, string s) {
        if (w.size()!=s.size()) return 0;
        for (int i=0; i!=w.size(); i++)
        {
            if (w[i][0]!=s[i]) return 0;
        }
        return 1;
    }
};