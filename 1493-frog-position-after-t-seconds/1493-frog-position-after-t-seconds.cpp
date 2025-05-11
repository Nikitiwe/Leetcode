class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& e, int t, int k) {
        vector<vector<int>> arr(n+1, vector<int>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back(e[i][1]);
            arr[e[i][1]].push_back(e[i][0]);
        }
        vector<double> ans(n+1, -1);
        ans[1] = 1;
        queue<int> v, l;
        v.push(1);
        l.push(0);
        while (v.size() > 0)
        {
            int id = v.front(); v.pop();
            int step = l.front(); l.pop();
            if ((id > 1 && arr[id].size() <= 1) || (id == 1 && arr[id].size() == 0)) continue;
            double p = ans[id] / (arr[id].size() - 1);
            if (id == 1) p = ans[id] / (arr[id].size());
            if (step < t)
            {
                for (int i=0; i!=arr[id].size(); i++) if (ans[arr[id][i]] < (-0.5))
                {
                    ans[arr[id][i]] = p;
                    v.push(arr[id][i]);
                    l.push(step+1);
                }
            }
            else continue;
            ans[id] = 0;
        }
        if (ans[k] > (-0.5)) return ans[k];
        else return 0;
    }
};