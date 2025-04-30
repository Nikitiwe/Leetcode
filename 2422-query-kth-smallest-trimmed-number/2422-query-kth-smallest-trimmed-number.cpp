class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans(q.size(), 0);
        for (int i=0; i!=q.size(); i++)
        {
            priority_queue<pair<string, int>> s;
            for (int j=0; j!=nums.size(); j++)
            {
                string t;
                for (int l=nums[j].size()-1; ; l--)
                {
                    t += nums[j][l];
                    if (t.size() == q[i][1]) break;
                }
                reverse(t.begin(), t.end());
                if (s.size() < q[i][0]) s.push({t, j});
                else
                {
                    if (s.top().first > t)
                    {
                        s.pop();
                        s.push({t, j});
                    }
                }
                ans[i] = s.top().second;
            }
        }
        return ans;
    }
};