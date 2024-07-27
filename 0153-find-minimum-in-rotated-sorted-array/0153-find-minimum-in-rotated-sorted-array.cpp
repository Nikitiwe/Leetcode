class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        if (nums[l]<nums[r]) return nums[l];
        while (l<r-1)
        {
            if (nums[(l+r)/2]>nums[l]) l=(l+r)/2;
            else r=(l+r)/2;
        }
        return min(nums[l], nums[r]);
    }
};