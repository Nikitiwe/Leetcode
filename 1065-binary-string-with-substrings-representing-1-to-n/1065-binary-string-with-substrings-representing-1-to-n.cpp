class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> m;
        m.insert(0);
        for (int i=0; i!=s.size(); i++)
        {
            int t = 0;
            for (int j=i; j<s.size(); j++)
            {
                t += (s[j] - '0');
                if (t > n) break;
                m.insert(t);
                t *= 2;
            }
        }
        if (m.size() == n + 1) return 1;
        else return 0;
    }
};