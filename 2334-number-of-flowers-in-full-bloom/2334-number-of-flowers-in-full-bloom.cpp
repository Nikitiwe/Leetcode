class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<int> ans(p.size(), 0);
        priority_queue<pair<int, int>> t;
        //unordered_set<int> s;
        int temp = 0;
        for (int i=0; i!=p.size(); i++)
        {
            //s.insert(p[i]);
            t.push({-p[i], -i});
        }
        for (int i=0; i!=f.size(); i++)
        {
            t.push({-f[i][0], 1});
            t.push({-f[i][1]-1, 2});
        }
        while (t.size() > 0)
        {
            int time = -t.top().first;
            int type = t.top().second;
            t.pop();
            if (type == 2) temp--;
            else if (type == 1) temp++;
            else
            {
                ans[-type] = temp;
            }
        }
        return ans;
    }
};