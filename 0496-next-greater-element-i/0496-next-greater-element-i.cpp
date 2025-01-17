class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        vector<int> ans(nums1.size(), -1);
        for (int i=0; i!=nums1.size(); i++)
        {
            bool isit=0;
            for (int j=0; j<nums.size(); j++)
            {
                if (isit==0)
                {
                    if (nums[j]==nums1[i]) isit=1;
                }
                else if (nums[j]>nums1[i])
                {
                    ans[i]=nums[j];
                    break;
                }
            }
        }
        return ans;
    }
};