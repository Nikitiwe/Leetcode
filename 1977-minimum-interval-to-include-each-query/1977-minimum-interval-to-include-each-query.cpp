class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& o, vector<int>& q) {
        map<int, int> s;
        priority_queue<pair<int, pair<int, int>>> x; // координата + тип + кто
        vector<int> ans(q.size(), -1);
        for (int i=0; i!=o.size(); i++)
        {
            x.push({-o[i][0], {3, o[i][1] - o[i][0] + 1}});
            x.push({-o[i][1], {1, o[i][1] - o[i][0] + 1}});
        }
        for (int i=0; i!=q.size(); i++)
        {
            x.push({-q[i], {2, i}});
        }
        while (x.size() > 0)
        {
            int type = x.top().second.first, who = x.top().second.second;
            x.pop();
            if (type == 3)
            {
                s[who]++;
            }
            else if (type == 2)
            {
                if (s.size() > 0) ans[who] = s.begin()->first;
            }
            else
            {
                s[who]--;
                if (s[who] == 0) s.erase(who);
            }
        }
        return ans;
    }
};