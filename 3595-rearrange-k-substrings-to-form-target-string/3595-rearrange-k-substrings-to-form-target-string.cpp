class Solution {
public:
    bool isPossibleToRearrange(string s, string w, int k) {
        k = s.size() / k;
        unordered_map<string, int> q;
        string t;
        for (int i=0; i!=s.size(); i++)
        {
            t += s[i];
            if (t.size() % k == 0)
            {
                q[t]++;
                t = "";
            }
        }
        for (int i=0; i!=w.size(); i++)
        {
            t += w[i];
            if (t.size() % k == 0)
            {
                q[t]--;
                t = "";
            }
        }
        for (auto i=q.begin(); i!=q.end(); i++)
        {
            if (i->second != 0) return 0;
        }
        return 1;
    }
};