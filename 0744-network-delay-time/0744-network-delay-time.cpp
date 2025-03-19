class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        stack<int> s;
        unordered_map<int, int> m;
        m[k] = 0;
        s.push(k);
        while(s.size() > 0)
        {
            int a = s.top();
            s.pop();
            for (int i=0; i!=t.size(); i++)
            {
                if (t[i][0] == a )
                {
                    if (m.count(t[i][1]) == 0 || m[t[i][1]] > m[a] + t[i][2])
                    {
                        m[t[i][1]] = m[a] + t[i][2];
                        s.push(t[i][1]);
                    }
                }
            }
        }
        if (m.size() < n) return -1;
        int ans = -1;
        for (auto i = m.begin(); i!=m.end(); i++) ans = max(ans, i->second);
        return ans;
    }
};