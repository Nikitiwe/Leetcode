class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int u=0, d=0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]==nums[i])
            {
                u++;
                d++;
            }
            else if (nums[i-1]<nums[i]) u++;
            else d++;
            if (u<i&&d<i) return 0;
        }
        return 1;
    }
};