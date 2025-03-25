class Solution {
public:
    /*bool isAlienSorted(vector<string>& s, string order) {
        unordered_map<char, int> m;
        for (int i=0; i!=26; i++) m[order[i]] = i;
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j<min(s[i].size(), s[i+1].size()); j++)
            {
                if (m[s[i][j]] > m[s[i+1][j]]) return 0;
                else if (m[s[i][j]] = m[s[i+1][j]]) continue;
                else break;
            }
        }
        return 1;
    }*/

    bool isAlienSorted(vector<string>& s, string order) {
    unordered_map<char, int> m;
    for (int i=0; i!=26; i++) m[order[i]] = i;
    for (int i=0; i<s.size()-1; i++)
    {
        bool equal = true;
        for (int j=0; j<min(s[i].size(), s[i+1].size()); j++)
        {
            if (m[s[i][j]] < m[s[i+1][j]])
            {
                equal = false;
                break;
            }
            if (m[s[i][j]] > m[s[i+1][j]]) return false;
        }
        if (equal && s[i].size() > s[i+1].size()) return false;
    }
    return true;
    }
};

