class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mi=*min_element(nums.begin(), nums.end()), ma=*max_element(nums.begin(), nums.end());
        for (int i=0; i!=nums.size(); i++)
        {
            if (mi<nums[i]&&nums[i]<ma) return nums[i];
        }
        return -1;
    }
};