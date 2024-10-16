class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size()<=2) return -1;
        if (nums[0]>nums[1]) swap(nums[0], nums[1]);
        if (nums[1]>nums[2]) swap(nums[1], nums[2]);
        if (nums[0]>nums[1]) swap(nums[0], nums[1]);
        return nums[1];
    }
};