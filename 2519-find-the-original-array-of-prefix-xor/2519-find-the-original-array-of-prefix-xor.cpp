class Solution {
public:
    vector<int> findArray(vector<int>& nums) {
        vector<int> ans = nums;
        for (int i=1; i<nums.size(); i++)
        {
            ans[i] = nums[i-1] ^ nums[i];
        }
        return ans;
    }
};