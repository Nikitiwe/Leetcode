class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if ( (i-k < 0 || (i-k >= 0 && nums[i] > nums[i-k]) ) && 
                (i+k >= nums.size() || (i+k < nums.size() && nums[i] > nums[i+k]) ))
                {
                    ans +=nums[i];
                }
        }
        return ans;
    }
};