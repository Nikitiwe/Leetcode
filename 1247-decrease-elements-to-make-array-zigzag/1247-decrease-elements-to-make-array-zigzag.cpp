class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int ans1=0, ans2=0;
        for (int i=1; i<nums.size(); i=i+2)
        {
            if (i<nums.size()-1&&(nums[i]>=nums[i-1]||nums[i]>=nums[i+1])) ans1+=max(nums[i]-nums[i-1]+1, nums[i]-nums[i+1]+1);
            else if (i==nums.size()-1&&nums[i]>=nums[i-1]) ans1+=nums[i]-nums[i-1]+1;
        }
        for (int i=0; i<nums.size(); i=i+2)
        {
            if (i>0&&i<nums.size()-1&&(nums[i]>=nums[i-1]||nums[i]>=nums[i+1])) ans2+=max(nums[i]-nums[i-1]+1, nums[i]-nums[i+1]+1);
            else if (i==nums.size()-1&&nums[i]>=nums[i-1]) ans2+=nums[i]-nums[i-1]+1;
            else if (i==0&&nums[i]>=nums[i+1]) ans2+=nums[i]-nums[i+1]+1;
        }
        return min(ans1, ans2);
    }
};