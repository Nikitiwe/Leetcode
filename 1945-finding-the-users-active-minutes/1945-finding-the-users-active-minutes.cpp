class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& l, int k) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> ans(k, 0);
        for (int i=0; i!=l.size(); i++)
        {
            m[l[i][0]].insert(l[i][1]);
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans[i->second.size()-1]++;
        }
        return ans;
    }
};