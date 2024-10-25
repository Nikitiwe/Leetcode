class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int l=0, r=1;
        while (1)
        {
            while (l<nums.size()&&nums[l]%2==0) l+=2;
            while (r<nums.size()&&nums[r]%2==1) r+=2;
            if (l<nums.size()&&r<nums.size()) swap(nums[l], nums[r]);
            else return nums;
        }
        return nums;
    }
};