class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        return max(0, *max_element(nums.begin(), nums.end())-k-*min_element(nums.begin(), nums.end())-k);
    }
};