class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0, sum = 0;
        m[0]++;
        for (int i=0; i!=nums.size(); i++)
        {
            sum += nums[i];
            ans += m[sum - k];
            m[sum]++;
        }
        return ans;
    }
};