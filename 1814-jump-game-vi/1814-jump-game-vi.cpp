class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        priority_queue<pair<int, int>> q; // сумма + последний индекс
        q.push({nums[0], 0});
        for (int i=1; i<nums.size(); i++)
        {
            while (q.size() > 0 && q.top().second < i-k) q.pop();
            int sum = q.top().first;
            if (i+1 == nums.size()) return sum+nums[i];
            q.push({sum+nums[i], i});
        }
        return -1;
    }
};