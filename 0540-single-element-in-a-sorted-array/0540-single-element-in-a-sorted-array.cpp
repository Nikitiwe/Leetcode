class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1, m;
        while (l<r)
        {
            m=(l+r)/2;
            if (m%2==0&&m<nums.size()-1&&nums[m]==nums[m+1])
            {
                l=m+1;
            }
            else if (m%2==0&&m<nums.size()-1&&nums[m]!=nums[m+1])
            {
                r=m;
            }
            else if (m%2==0&&m==nums.size()-1)
            {
                return m;
            }
            else if (m%2==1&&nums[m-1]==nums[m])
            {
                l=m+1;
            }
            else if (m%2==1&&nums[m-1]!=nums[m])
            {
                r=m;
            }
        }
        return nums[(l+r)/2];
    }
};