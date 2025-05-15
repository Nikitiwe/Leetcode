class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& l, int x, vector<int>& q) {
        vector<int> ans(q.size(), 0);
        priority_queue<tuple<int, int, int>> m; // - время + тип + ид
        for (int i=0; i!=l.size(); i++)
        {
            m.push({ - l[i][1], 1, l[i][0]}); // 1 родить
            m.push({ - l[i][1] - x - 1, 2, l[i][0]}); // 2 убить
        }
        for (int i=0; i!=q.size(); i++)
        {
            m.push({ - q[i], 0, i});
        }
        unordered_map<int, int> s;
        while (m.size() > 0)
        {
            auto[time, type, id] = m.top();
            m.pop();
            if (type == 1)
            {
                s[id]++;
            }
            else if (type == 2)
            {
                s[id]--;
                if (s[id] == 0) s.erase(id);
            }
            else
            {
                ans[id] = n - s.size();
            }
        }
        return ans;
    }
};