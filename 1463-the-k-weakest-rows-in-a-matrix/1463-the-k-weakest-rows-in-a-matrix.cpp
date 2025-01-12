class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& m, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> q;
        for (int i=0; i!=m.size(); i++)
        {
            int t=0;
            for (int j=0; j!=m[0].size(); j++) t+=m[i][j];
            q.push({t, i});
        }
        while (q.size()>0)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        while (ans.size()>k) ans.pop_back();
        return ans;
    }
};