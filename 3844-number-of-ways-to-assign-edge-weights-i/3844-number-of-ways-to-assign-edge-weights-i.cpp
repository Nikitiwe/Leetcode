class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& e) {
        long mod = 1e9 + 7;
        vector<int> h(e.size() + 1, 0);
        vector<vector<int>> arr(e.size() + 1, vector<int>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0] - 1].push_back(e[i][1] - 1);
            arr[e[i][1] - 1].push_back(e[i][0] - 1);
        }
        queue<int> q;
        q.push(0);
        set<int> s;
        s.insert(0);
        int ma = 0;
        while (q.size() > 0)
        {
            int id = q.front();
            for (int i=0; i<arr[id].size(); i++)
            {
                if (s.count(arr[id][i]) == 0)
                {
                    s.insert(arr[id][i]);
                    q.push(arr[id][i]);
                    h[arr[id][i]] = h[id] + 1;
                    ma = max(ma, h[arr[id][i]]);
                }
            }
            q.pop();
        }
        int ans = 1;
        for (int i=1; i<ma; i++)
        {
            ans *= 2;
            ans %= mod;
        }
        return ans;
    }
};