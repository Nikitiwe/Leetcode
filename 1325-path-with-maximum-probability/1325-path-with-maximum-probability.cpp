class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> arr(n, vector<pair<int, double>>());
        for (int i=0; i!=edges.size(); i++)
        {
            arr[edges[i][0]].push_back({edges[i][1], succProb[i]});
            arr[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> ans(n, 0);
        ans[start_node] = 1;
        queue<int> q;
        q.push(start_node);
        while (q.size() > 0)
        {
            int x = q.front();
            double p = ans[x];
            q.pop();
            for (int i=0; i!=arr[x].size(); i++)
            {
                if (ans[arr[x][i].first] < p * arr[x][i].second)
                {
                    ans[arr[x][i].first] = p * arr[x][i].second;
                    q.push(arr[x][i].first);
                }
            }
        }
        return ans[end_node];
    }
};