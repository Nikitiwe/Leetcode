class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 2;
        for (int i = -250; i <= 250; i++)
        {
            //vector<int> arr(nums.size(), 1);
            unordered_map<int, int> m;
            m[nums[0]] = 1;
            for (int j = 1; j<nums.size(); j++)
            {
                m[nums[j]] = m[nums[j] - i] + 1;
                ans = max(ans, m[nums[j]]);
            }
        }
        return ans;
    }
};