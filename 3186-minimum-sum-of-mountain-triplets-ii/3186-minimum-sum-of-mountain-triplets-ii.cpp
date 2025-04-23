class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = 1000000000;
        vector<int> l(nums.size(), -1);
        int mi = nums[0];
        for (int i=1; i<nums.size()-1; i++)
        {
            if (nums[i] > mi) l[i] = mi;
            mi = min(mi, nums[i]);
        }
        mi = nums.back();
        for (int i = nums.size()-2; i>=1; i--)
        {
            if (nums[i] > mi && l[i] != -1)
            {
                ans = min(ans, l[i] + mi + nums[i]);
            }
            mi = min(mi, nums[i]);
        }
        if (ans < 1000000000) return ans;
        else return -1;
    }
};