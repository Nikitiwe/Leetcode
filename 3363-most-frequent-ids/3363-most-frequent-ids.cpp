class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& f) {
        vector<long long> ans(nums.size(), 0);
        unordered_map<int, long long> m;
        priority_queue<pair<long long, int>> q;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]] += f[i];
            q.push({m[nums[i]], nums[i]});
            while (m[q.top().second] != q.top().first) q.pop();
            ans[i] = q.top().first;
        }
        return ans;
    }
};