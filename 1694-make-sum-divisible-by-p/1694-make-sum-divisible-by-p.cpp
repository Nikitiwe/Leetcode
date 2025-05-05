class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        nums[0] %= p;
        for (int i=1; i<nums.size(); i++)
        {
            nums[i] += nums[i-1];
            nums[i] %= p;
        }
        if (nums.back() == 0) return 0;
        int ans = 1000000000;
        unordered_map<int, int> m;
        m[0] = -1;
        int r = nums.back();
        for (int i=0; i<nums.size(); i++)
        {
            if (m.count((nums[i] - r + p) % p) != 0)
            {
                ans = min(ans, i - m[(nums[i] - r + p) % p]);
            }
            m[nums[i]] = i;
        }
        if (ans < nums.size()) return ans;
        else return -1;
    }
};