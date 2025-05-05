class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& e, vector<int>& nums) {
        vector<vector<pair<int, int>>> arr(nums.size() + 1, vector<pair<int, int>>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back({e[i][1], e[i][2]});
            arr[e[i][1]].push_back({e[i][0], e[i][2]});
        }
        vector<int> cost(nums.size(), 1000000000);
        vector<int> time(nums.size(), 1000000000);
        //priority_queue<vector<int>> q; // -деньги -время ид
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.push({ nums[0], 0, 0});
        cost[0] = nums[0];
        time[0] = 0;
        int ans = 1000000000;
        while (q.size() > 0)
        {
            /*int i = q.top()[2];
            int t = q.top()[1];
            int m = - q.top()[0];*/
            auto [m, t, i] = q.top();
            q.pop();
            if (i == nums.size() - 1) return m;
            for (int j = 0; j<arr[i].size(); j++)
            {
                if (t + arr[i][j].second <= maxTime && (m + nums[arr[i][j].first] < cost[arr[i][j].first] || t + arr[i][j].second < time[arr[i][j].first]))
                {
                    q.push({ m + nums[arr[i][j].first], t + arr[i][j].second, arr[i][j].first});
                    cost[arr[i][j].first] = min(cost[arr[i][j].first], m + nums[arr[i][j].first]);
                    time[arr[i][j].first] = min(time[arr[i][j].first], t + arr[i][j].second);
                }
            }
        }
        if (ans < 1000000000) return ans;
        else return -1;
    }
};