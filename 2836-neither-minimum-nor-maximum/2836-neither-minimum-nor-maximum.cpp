class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size()<=2) return -1;
        sort(nums.begin(), nums.begin()+3);
        return nums[1];
    }
};