class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while (1)
        {
            if (nums[l]==2||nums[l]==3||nums[l]==5||nums[l]==7) break;
            else if (nums[l]==1||nums[l]%2==0||nums[l]%3==0||nums[l]%5==0||nums[l]%7==0) l++;
            else break;
        }
        while (1)
        {
            if (nums[r]==2||nums[r]==3||nums[r]==5||nums[r]==7) break;
            if (nums[r]==1||nums[r]%2==0||nums[r]%3==0||nums[r]%5==0||nums[r]%7==0) r--;
            else break;
        }
        return r-l;
    }
};