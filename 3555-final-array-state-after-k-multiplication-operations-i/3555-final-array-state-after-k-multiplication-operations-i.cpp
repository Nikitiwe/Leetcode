class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i=0; i!=k; i++)
        {
            nums[distance(nums.begin(), min_element(nums.begin(), nums.end()))]*=multiplier;
        }
        return nums;
    }
};