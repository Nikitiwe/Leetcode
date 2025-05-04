class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        k++;
        vector<vector<pair<int, int>>> arr(n, vector<pair<int, int>>());
        for (int i=0; i!=f.size(); i++)
        {
            arr[f[i][0]].push_back({f[i][1], f[i][2]});
        }
        int ans = 1000000000;
        queue<int> id, l, p;
        id.push(src);
        l.push(0);
        p.push(0);
        vector<vector<int>> res(n, vector<int>(k+1, 1000000000));
        res[src][0] = 0;
        while (id.size() > 0)
        {
            int i = id.front(); id.pop();
            int d = l.front(); l.pop();
            int price = p.front(); p.pop();
            if (d > k) continue;
            if (i == dst) ans = min(ans, price);
            if (d < k) for (int j=0; j<arr[i].size(); j++) if (price + arr[i][j].second < res[arr[i][j].first][d+1])
            {
                id.push(arr[i][j].first);
                l.push(d+1);
                p.push(price + arr[i][j].second);
                res[arr[i][j].first][d+1] = price + arr[i][j].second;
            }
        }
        if (ans < 1000000000) return ans;
        else return -1;
    }
};