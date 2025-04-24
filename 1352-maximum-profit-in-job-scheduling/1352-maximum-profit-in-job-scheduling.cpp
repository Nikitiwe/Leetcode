class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int ans = 0;
        int t = 0;
        priority_queue<pair<int, pair<int, int>>> q; // время + тип/ид + сумма
        for (int i=0; i!=s.size(); i++)
        {
            q.push({-s[i], {i, 0}});
        }
        while (q.size() > 0)
        {
            int id = q.top().second.first;
            if (id < 100000)
            {
                q.push({-e[id], {100000, t + p[id]}});
            }
            else
            {
                t = max(t, q.top().second.second);
                ans = max(ans, t);
            }
            q.pop();
        }
        return ans;
    }
};