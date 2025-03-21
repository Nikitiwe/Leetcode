class Solution {
public:
    int numSpecialEquivGroups(vector<string>& s) {
        unordered_map<string, int> m;
        for (int i=0; i!=s.size(); i++)
        {
            string t1, t2;
            for (int j=0; j<s[i].size(); j+=2) t1 += s[i][j];
            for (int j=1; j<s[i].size(); j+=2) t2 += s[i][j];
            sort(t1.begin(), t1.end());
            sort(t2.begin(), t2.end());
            m[t1 + ':' + t2]++;
        }
        return m.size();
    }
};