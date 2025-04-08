class Solution {
public:
    vector<int> findArray(vector<int>& nums) {
        vector<int> ans = nums;
        int prev = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            //ans[i] = nums[i-1] ^ ans[i-1];
            ans[i] = nums[i-1] ^ nums[i];
            //prev ^= ans[i];
        }
        return ans;
    }
};