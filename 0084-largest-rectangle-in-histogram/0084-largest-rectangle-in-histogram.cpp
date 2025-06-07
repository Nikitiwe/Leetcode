class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<pair<int, int>> s; // высота + индекс
        int ans = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            int l = i;
            while (s.size() > 0 && s.top().first > nums[i])
            {
                ans = max(ans, (i - s.top().second) * s.top().first);
                l = s.top().second;
                s.pop();
            }
            s.push({nums[i], l});
        }
        if (s.size() > 0)
        {
            int b = nums.size();
            while (s.size() > 0)
            {
                ans = max(ans, (b - s.top().second) * s.top().first);
                s.pop();
            }
        }
        return ans;
    }
};