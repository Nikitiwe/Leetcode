class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& n) {
        unordered_map<int, int> m;
        for (int i=0; i!=n.size(); i++)
        {
            m[n[i][1]]++;
            m[n[i][0]]+=0;
        }
        vector<int> ans0, ans1;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==0) ans0.push_back(i->first);
            else if (i->second==1) ans1.push_back(i->first);
        }
        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        return {ans0, ans1};
    }
};