class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0, l=0, r=newInterval[1];
        while (i<intervals.size()&&intervals[i][1]<newInterval[0])
        {
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        if (i==intervals.size()) {ans.push_back({newInterval[0], newInterval[1]}); return ans;}
        l=min(newInterval[0], intervals[i][0]);
        while (i<intervals.size()&&intervals[i][0]<=newInterval[1])
        {
            r=max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back({l, r});
        while (i<intervals.size())
        {
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return ans;
    }
};