class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l=intervals[0][0], r=intervals[0][1];
        for (int i=1; i<intervals.size(); i++)
        {
            if (intervals[i][0]<=r) r=max(intervals[i][1], r);
            else
            {
                ans.push_back({l, r});
                l=intervals[i][0]; r=intervals[i][1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};