class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int l=0, r=0;
        vector<vector<int>> ans;
        while (l<f.size()&&r<s.size())
        {
            if (min(f[l][1], s[r][1])-max(f[l][0], s[r][0])>=0)
            {
                ans.push_back({max(f[l][0], s[r][0]), min(f[l][1], s[r][1])});
            }
            if (f[l][1]<=s[r][1]) l++;
            else r++;
        }
        return ans;
    }
};