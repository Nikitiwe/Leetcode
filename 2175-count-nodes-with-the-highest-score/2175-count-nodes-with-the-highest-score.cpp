class Solution {
public:
    int f(unordered_map<int, pair<int, int>> &m, vector<int> &l, vector<int> &r, int i)
    {
        int lc = 0;
        if (m.count(i) != 0) lc = f(m, l, r, m[i].first);
        int rc = 0;
        if (m.count(i) != 0 && m[i].second != -1) rc = f(m, l, r, m[i].second);
        l[i] = lc;
        r[i] = rc;
        return lc + rc + 1;
    }

    int countHighestScoreNodes(vector<int>& p) {
        vector<int> l(p.size(), 0), r = l;
        unordered_map<int, pair<int, int>> m;
        for (int i=1; i<p.size(); i++)
        {
            if (m.count(p[i]) == 0) m[p[i]] = {i, -1};
            else
            {
                pair<int, int> t = m[p[i]];
                t.second = i;
                m[p[i]] = t;
            }
        }
        f(m, l, r, 0);
        //int i = 2;
        long long score = 0, ans = 0;
        //return max(ans, max(l[i], 1) * max(r[i], 1) * max(((int)p.size() - l[i] - r[i] - 1), 1));
        for (int i=0; i!=p.size(); i++)
        {
            long long t = max((long long)l[i], (long long)1) * max((long long)r[i], (long long)1) * max(((long long)p.size() - (long long)l[i] - (long long)r[i] - (long long)1), (long long)1);
            if (t == score) ans++;
            else if (t > score)
            {
                ans = 1;
                score = t;
            }
        }
        return ans;
    }
};