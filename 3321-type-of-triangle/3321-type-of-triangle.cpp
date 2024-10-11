class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[0]>nums[1]) swap(nums[0], nums[1]);
        if (nums[1]>nums[2])
        {
            swap(nums[1], nums[2]);
            if (nums[0]>nums[1]) swap(nums[0], nums[1]);
        }
        if (nums[0]+nums[1]<=nums[2]) return "none";
        if (nums[0]==nums[1]&&nums[1]==nums[2]) return "equilateral";
        else if (nums[0]==nums[1]||nums[1]==nums[2]) return "isosceles";
        else return "scalene";
    }
};