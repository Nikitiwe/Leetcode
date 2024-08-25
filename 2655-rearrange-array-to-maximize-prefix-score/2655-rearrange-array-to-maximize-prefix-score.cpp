class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long sum=0;
        for (int i=nums.size()-1; i>=0; i--)
        {
            sum+=nums[i];
            if (sum<=0) return nums.size()-1-i;
        }
        return nums.size();
    }
};