class Solution {
public:
    vector<int> decode(vector<int>& nums, int f) {
        vector<int> ans(nums.size()+1, f);
        for (int i=0; i!=nums.size(); i++) ans[i+1] = ans[i] ^ nums[i];
        return ans;
    }
};