class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while (l<r-1)
        {
            if (nums[(l+r)/2]>=target) r=(l+r)/2;
            else l=(l+r)/2;
        }
        if (nums[l]==target) return l;
        if (l+1<nums.size()&&nums[l+1]==target) return l+1;
        else return -1;
    }
};