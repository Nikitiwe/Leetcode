class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> arr(nums.size() + 1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i+1] += nums[i];
            arr[i+1] += arr[i];
        }
        int ans = 0;
        unordered_map<int, int> m;
        int sum = 0;
        int id = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(nums[i]) == 0)
            {
                sum += nums[i];
                m[nums[i]] = i;
                ans = max(ans, sum);
            }
            else
            {
                id = max(id, m[nums[i]]);
                sum = arr[i+1] - arr[id + 1];
                m[nums[i]] = i;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};