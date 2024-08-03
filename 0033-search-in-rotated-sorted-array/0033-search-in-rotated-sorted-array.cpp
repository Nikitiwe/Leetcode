class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while (l<=r)
        {
            mid=(l+r)/2;
            if (nums[mid]==target) return mid;
            else if ((nums[mid]>nums[l]&&nums[mid]>target&&nums[l]<=target)||
            (nums[mid]<nums[l]&&(nums[mid]>target||nums[l]<=target))) r=mid-1;
            else l=mid+1;
        }
        if (l<nums.size()&&nums[l]==target) return l;
        else return -1;
    }
};