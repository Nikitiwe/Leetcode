class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (int i=0; i!=r.size(); i++)
        {
            m[r[i][0]]++;
            m[r[i][1]]++;
            s.insert(r[i][0]*1000 + r[i][1]);
            s.insert(r[i][1]*1000 + r[i][0]);
        }
        int ans = 0;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (i != j)
                {
                    int t = m[i] + m[j];
                    if (s.count(i*1000 + j) == 1 || s.count(j*1000 + i) == 1) t--;
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};