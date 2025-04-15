class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (int i=0; i!=r.size(); i++)
        {
            m[r[i][0]]++;
            m[r[i][1]]++;
            s.insert(min(r[i][0], r[i][1])*1000 + max(r[i][0], r[i][1]));
        }
        int ans = 0;
        for (int i=0; i!=n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int t = m[i] + m[j];
                if (s.count(i*1000 + j) == 1) t--;
                ans = max(ans, t);
            }
        }
        return ans;
    }
};