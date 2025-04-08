class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0, st = 1;
        for (int i=0; i!=maximumBit; i++) st *= 2;
        st--;
        for (int i=0; i!=nums.size(); i++) x ^= nums[i];
        vector<int> ans(nums.size(), 0);
        for (int i=0; i!=nums.size(); i++)
        {
            ans[i] = x ^ st;
            x ^= nums[nums.size() - 1 - i];
        }
        return ans;
    }
};