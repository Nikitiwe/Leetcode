class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& arr) {
        priority_queue<pair<long, int>> t; // время + id
        priority_queue<pair<int, int>> r; // длительность + id
        vector<int> ans;
        for (int i=0; i!=arr.size(); i++)
        {
            t.push({-arr[i][0], i});
        }
        t.push({0, -1});
        while (t.size() > 0)
        {
            long time = - t.top().first;
            int id = t.top().second;
            t.pop();
            if (id == -1)
            {
                if (r.size() > 0)
                {
                    int i = - r.top().second;
                    int l = - r.top().first;
                    r.pop();
                    ans.push_back(i);
                    t.push({-(time + l), -1});
                }
                else
                {
                    int nexttime = - t.top().first;
                    t.push({-nexttime, -1});
                }
            }
            else
            {
                int l = arr[id][1];
                r.push({-l, -id});
            }
            if (ans.size() == arr.size()) break;
        }
        return ans;
    }
};