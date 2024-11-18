class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int id=0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>=0&&nums[i]<=abs(nums[id])) id=i;
            else if (nums[i]<0&&-nums[i]<abs(nums[id])) id=i;
        }
        return nums[id];
    }
};