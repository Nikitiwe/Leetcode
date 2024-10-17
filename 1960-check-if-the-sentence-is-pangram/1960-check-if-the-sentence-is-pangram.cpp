class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char> m;
        for (int i=0; i!=s.size(); i++)
        {
            m.insert(s[i]);
        }
        if (m.size()==26) return 1;
        else return 0;
    }
};