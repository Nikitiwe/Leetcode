class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=1, temp=1;
        for (int i=1; i!=nums.size(); i++)
        {
            if (nums[i]>nums[i-1])
            {
                temp++;
                ans=max(ans, temp);
            }
            else temp=1;
        }
        return ans;
    }
};