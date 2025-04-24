class Solution {
public:
    int longestPath(vector<int>& p, string w) {
        int ans = 1;
        unordered_map<int, int> m;
        vector<vector<int>> arr(p.size(), vector<int>(2, 0));
        for (int i=1; i<p.size(); i++) m[p[i]]++;
        queue<int> q;
        for (int i=1; i<p.size(); i++)
        {
            if (m.count(i) == 0)
            {
                if (w[i] != w[p[i]] )
                {
                    if (arr[p[i]][0] == 0) arr[p[i]][0] = 1;
                    else arr[p[i]][1] = 1;
                }
                m[p[i]]--;
                if (m[p[i]] == 0) q.push(p[i]);
            }
        }
        while (q.size() > 0)
        {
            int id = q.front();
            q.pop();
            ans = max(ans, arr[id][0] + arr[id][1] + 1);
            arr[id][0]++;
            arr[id][1]++;
            if (id != 0)
            {
                if (w[id] != w[p[id]] )
                {
                    if (arr[id][0] >= arr[p[id]][0] )
                    {
                        arr[p[id]][1] = arr[p[id]][0];
                        arr[p[id]][0] = arr[id][0];
                    }
                    else if (arr[id][0] > arr[p[id]][1] ) arr[p[id]][1] = arr[id][0];
                }
                m[p[id]]--;
                if (m[p[id]] == 0) q.push(p[id]);
            }
        }
        return ans;
    }
};