class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        for (int i=0; i<nums.size()-3; i++)
        {
            if (nums[i+1]*2==nums[i]+nums[i+2]||nums[i+1]*2==nums[i]+nums[i+3])
                swap(nums[i], nums[i+1]);
        }
        if (nums[nums.size()-2]*2==nums[nums.size()-1]+nums[nums.size()-3])
            swap(nums[nums.size()-1], nums[nums.size()-2]);
        return nums;
    }
};