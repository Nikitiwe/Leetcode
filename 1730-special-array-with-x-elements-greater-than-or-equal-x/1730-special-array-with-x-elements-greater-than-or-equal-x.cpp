class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0]>=nums.size()) return nums.size();
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]!=nums[i])
            {
                if (nums[i-1]<nums.size()-i&&nums[i]>=nums.size()-i) return nums.size()-i;
            }
        }
        return -1;
    }
};