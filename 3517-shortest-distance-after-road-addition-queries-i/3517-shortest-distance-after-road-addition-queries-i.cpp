class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<int> ans(q.size(), 0);
        vector<vector<int>> from(n, vector<int>());
        vector<int> arr(n, 0);
        for (int i=0; i!=arr.size(); i++) arr[i] = i;
        for (int i=0; i+1<arr.size(); i++) from[i].push_back(i+1);
        for (int i=0; i!=q.size(); i++)
        {
            from[q[i][0]].push_back(q[i][1]);
            queue<int> v, d;
            v.push(q[i][1]);
            d.push(arr[q[i][0]] + 1);
            while (v.size() > 0)
            {
                int vv = v.front(); v.pop();
                int dd = d.front(); d.pop();
                if (dd < arr[vv])
                {
                    arr[vv] = dd;
                    for (int j = 0; j!=from[vv].size(); j++)
                    {
                        v.push(from[vv][j]);
                        d.push(dd + 1);
                    }
                }
                ans[i] = arr.back();
            }
        }
        return ans;
    }
};