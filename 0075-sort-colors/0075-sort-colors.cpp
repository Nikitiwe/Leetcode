class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size()==2) {if (nums[0]>nums[1]) swap(nums[0], nums[1]);}
        else if (nums.size()!=1)
        {
        int l=0, r=nums.size()-1, s;
        while (nums[l]==0) l++;
        while (nums[r]==2) r--;
        s=l;
        while (s<=r)
        {
            if (nums[s]==0)
            {
                swap(nums[s], nums[l]);
                l++;
                if (l>s) s++;
                if (l==s) s++;
            }
            else if (nums[s]==1)
            {
                s++;
            }
            else if (nums[s]==2)
            {
                swap(nums[s], nums[r]);
                r--;
            }
        }

        }
    }
};