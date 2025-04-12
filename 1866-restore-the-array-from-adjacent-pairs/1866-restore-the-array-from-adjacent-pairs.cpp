class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& p) {
        int id = 0;
        unordered_map<int, pair<int, int>> s;
        unordered_map<int, int> c;
        for (int i=0; i!=p.size(); i++)
        {
            int x = p[i][0], y = p[i][1];
            if (s.count(x) == 0)
            {
                s[x].first = y;
            }
            else s[x].second = y;
            if (s.count(y) == 0)
            {
                s[y].first = x;
            }
            else s[y].second = x;
            c[x]++;
            c[y]++;
        }
        for (auto i = c.begin(); i!=c.end(); i++) if (i->second == 1)
        {
            id = i->first;
            break;
        }
        vector<int> ans(1, id);
        ans.push_back(s[id].first);
        for (int i=1; i<p.size(); i++)
        {
            if (ans[ans.size()-2] == s[ans.back()].first) ans.push_back(s[ans.back()].second);
            else ans.push_back(s[ans.back()].first);
        }
        return ans;
    }
};