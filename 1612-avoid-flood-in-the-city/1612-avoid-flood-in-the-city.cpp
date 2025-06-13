class Solution {
public:
    vector<int> avoidFlood(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        vector<int> arr(nums.size(), -1);
        unordered_set<int> s;
        unordered_map<int, int> m;
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (nums[i] != 0)
            {
                if (m.count(nums[i]) != 0) arr[i] = m[nums[i]];
                m[nums[i]] = i;
            }
        }
        priority_queue<pair<int, int>> q;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (s.count(nums[i]) != 0) return {};
                s.insert(nums[i]);
                if (arr[i] != -1) q.push({ - arr[i], nums[i]});
            }
            else
            {
                if (q.size() > 0)
                {
                    ans[i] = q.top().second;
                    s.erase(ans[i]);
                    q.pop();
                }
                else ans[i] = 1;
            }
        }
        return ans;
    }
};