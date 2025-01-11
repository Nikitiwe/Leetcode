class Solution {
public:
    string destCity(vector<vector<string>>& s) {
        unordered_set<string> m;
        for (int i=0; i!=s.size(); i++) m.insert(s[i][0]);
        for (int i=0; i!=s.size(); i++) if (m.count(s[i][1])==0) return s[i][1];
        return "0";
    }
};