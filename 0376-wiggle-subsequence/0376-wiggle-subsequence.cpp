class Solution {
public:
    int wiggleMaxLength(vector<int>& nums1) {
        vector<int> nums(1, 0);
        nums[0]=nums1[0];
        for (int i=1; i!=nums1.size(); i++)
        {
            if (nums1[i]!=nums[nums.size()-1]) nums.push_back(nums1[i]);
        }
        if (nums.size()==1) return 1;
        int ans=2;
        for (int i=0; i!=nums.size()-1; i++)
        {
            nums[i]=nums[i+1]-nums[i];
        }
        for (int i=1; i!=nums.size()-1; i++)
        {
            if (nums[i]*nums[i-1]<0) ans++;
        }
        return ans;
    }
};