class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size()<5) return 0;
        sort(nums.begin(), nums.end());
        return min({nums[nums.size()-1]-nums[3], 
                    nums[nums.size()-2]-nums[2], 
                    nums[nums.size()-3]-nums[1], 
                    nums[nums.size()-4]-nums[0] });
    }
};