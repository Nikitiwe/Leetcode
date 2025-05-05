class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> q; // -х + чо сделать: тип + высота
        for (int i=0; i!=nums.size(); i++)
        {
            q.push({ - nums[i][0], nums[i][2]});
            q.push({ - nums[i][1], - nums[i][2]});
        }
        unordered_map<int, int> m; // высота + число
        priority_queue<int> h;
        while (q.size() > 0)
        {
            int x = - q.top().first;
            int y = q.top().second;
            q.pop();
            if (y > 0)
            {
                m[y]++;
                h.push(y);
            }
            else m[-y]--;
            while (h.size() > 0 && m[h.top()] <= 0) h.pop();
            
            if (ans.size() == 0) ans.push_back({x, h.top()});
            else if (ans.size() > 0 && h.size() > 0 && ans[ans.size()-1][1] != h.top())
            {
                ans.push_back({x, h.top()});
            }
            else if (ans.size() > 0 && h.size() == 0 && ans[ans.size()-1][1] != 0)
            {
                ans.push_back({x, 0});
            }
        }
        return ans;
    }
};